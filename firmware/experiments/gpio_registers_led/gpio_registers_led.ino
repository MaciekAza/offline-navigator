// Offline Navigator — educational GPIO experiment
// Board: Arduino UNO R3 / ATmega328P
// D13 on UNO maps to PB5 on ATmega328P.
// Status: example prepared for testing; hardware execution has not yet been confirmed.

void setup() {
    // Set DDRB bit 5: configure PB5/D13 as an output.
    // |= sets this bit without changing other DDRB bits.
    DDRB |= _BV(DDB5);
}

void loop() {
    // Set PORTB bit 5 high: the built-in LED on D13 should turn on.
    PORTB |= _BV(PORTB5);
    delay(500);

    // Clear only PORTB bit 5; preserve all other PORTB bits.
    PORTB &= ~_BV(PORTB5);
    delay(500);
}
