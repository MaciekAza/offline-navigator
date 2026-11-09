// Offline Navigator — wykrywanie zbocza naciśnięcia przez polling
// Arduino UNO R3 / ATmega328P
// Przycisk między D12/PB4 a GND; LED D13/PB5.
// Celowo bez debounce: mechaniczne drgania mogą dawać wielokrotne przełączenia.

bool previousPressed = false;
bool ledOn = false;

void setup() {
    DDRB |= _BV(DDB5);
    DDRB &= ~_BV(DDB4);
    PORTB |= _BV(PORTB4);     // Pull-up
    PORTB &= ~_BV(PORTB5);    // LED off
}

void loop() {
    const bool pressed = ((PINB & _BV(PINB4)) == 0);

    // Nowe naciśnięcie: teraz wciśnięty, poprzednio zwolniony.
    if (pressed && !previousPressed) {
        ledOn = !ledOn;
        if (ledOn) {
            PORTB |= _BV(PORTB5);
        } else {
            PORTB &= ~_BV(PORTB5);
        }
    }

    previousPressed = pressed;
}
