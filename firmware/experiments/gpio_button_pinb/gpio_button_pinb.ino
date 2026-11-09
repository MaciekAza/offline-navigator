// Offline Navigator — odczyt GPIO przez PINB
// Arduino UNO R3 / ATmega328P
// Przycisk między D12/PB4 a GND; wbudowana LED D13/PB5.
// Stan zwolniony = HIGH (pull-up), naciśnięty = LOW.

void setup() {
    DDRB |= _BV(DDB5);        // PB5 / D13 jako wyjście LED
    DDRB &= ~_BV(DDB4);       // PB4 / D12 jako wejście
    PORTB |= _BV(PORTB4);     // Włącz wewnętrzny pull-up na PB4
    PORTB &= ~_BV(PORTB5);    // LED początkowo zgaszona
}

void loop() {
    if ((PINB & _BV(PINB4)) == 0) {
        PORTB |= _BV(PORTB5);     // Przycisk naciśnięty: LED świeci
    } else {
        PORTB &= ~_BV(PORTB5);    // Przycisk zwolniony: LED gaśnie
    }
}
