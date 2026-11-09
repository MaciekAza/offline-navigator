#include <avr/interrupt.h>
#include <util/atomic.h>

volatile bool buttonEvent = false;

void setup() {
    DDRB |= _BV(DDB5);
    PORTB &= ~_BV(PORTB5);

    DDRD &= ~_BV(DDD2);
    PORTD |= _BV(PORTD2);

    EICRA = (EICRA & ~(_BV(ISC01) | _BV(ISC00)))
             | _BV(ISC01);

    EIFR = _BV(INTF0);
    EIMSK |= _BV(INT0);

    sei();
}

ISR(INT0_vect) {
    buttonEvent = true;
}

void loop() {
    bool event;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        event = buttonEvent;
        buttonEvent = false;
    }

    if (event) {
        PORTB ^= _BV(PORTB5);
    }
}