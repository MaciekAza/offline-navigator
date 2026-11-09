// Offline Navigator — edukacyjny eksperyment GPIO
// Arduino UNO R3 / ATmega328P
// D13 na UNO mapuje się na PB5.
// Status: użytkownik potwierdził, że wgrany szkic migał LED D13.

void setup() {
    // Ustaw bit 5 w DDRB: PB5/D13 staje się wyjściem.
    DDRB |= _BV(DDB5);
}

void loop() {
    // Ustaw PB5 w stan wysoki — LED D13 świeci.
    PORTB |= _BV(PORTB5);
    delay(500);

    // Wyzeruj tylko bit 5, zachowując pozostałe bity PORTB.
    PORTB &= ~_BV(PORTB5);
    delay(500);
}
