// Offline Navigator — demonstracja przerwania zewnętrznego INT0
// Arduino UNO R3 / ATmega328P
// Przycisk między D2/PD2/INT0 a GND; LED na D13/PB5.
// Reaguje na zbocze opadające. Celowo bez debounce.
// buttonEvent jest flagą bool — kilka zdarzeń może zlać się w jedno.

#include <avr/interrupt.h>
#include <util/atomic.h>

volatile bool buttonEvent = false;

void setup() {
    DDRB |= _BV(DDB5);        // LED D13 / PB5 jako wyjście
    PORTB &= ~_BV(PORTB5);    // LED początkowo zgaszona

    DDRD &= ~_BV(DDD2);       // D2 / PD2 / INT0 jako wejście
    PORTD |= _BV(PORTD2);     // Wewnętrzny pull-up

    // ISC01:ISC00 = 10: zbocze opadające (HIGH -> LOW)
    EICRA = (EICRA & ~(_BV(ISC01) | _BV(ISC00))) | _BV(ISC01);

    EIFR = _BV(INTF0);        // W1C: skasuj starą flagę INT0
    EIMSK |= _BV(INT0);       // Zezwól na obsługę źródła INT0
    sei();                    // Globalne zezwolenie na przerwania
}

ISR(INT0_vect) {
    buttonEvent = true;       // ISR tylko zgłasza zdarzenie
}

void loop() {
    bool event;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        event = buttonEvent;
        buttonEvent = false;
    }

    if (event) {
        PORTB ^= _BV(PORTB5); // Zmień stan LED poza ISR
    }
}
