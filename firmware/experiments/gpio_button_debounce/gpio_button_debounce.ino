// Offline Navigator — przycisk z eliminacją drgań styków
// Arduino UNO R3 / ATmega328P
// Przycisk między D12/PB4 a GND; wbudowana LED D13/PB5.
// Status: użytkownik potwierdził działanie po wgraniu.

const unsigned long DEBOUNCE_MS = 30UL;

bool lastRawPressed = false;
bool stablePressed = false;
bool ledOn = false;
unsigned long lastRawChangeMs = 0;

void setup() {
    DDRB |= _BV(DDB5);        // PB5 / D13 jako wyjście
    DDRB &= ~_BV(DDB4);       // PB4 / D12 jako wejście
    PORTB |= _BV(PORTB4);     // Wewnętrzny pull-up
    PORTB &= ~_BV(PORTB5);    // LED początkowo zgaszona
}

void loop() {
    const bool rawPressed = ((PINB & _BV(PINB4)) == 0);
    const unsigned long now = millis();

    if (rawPressed != lastRawPressed) {
        lastRawPressed = rawPressed;
        lastRawChangeMs = now;
    }

    if ((now - lastRawChangeMs >= DEBOUNCE_MS) &&
        (rawPressed != stablePressed)) {
        stablePressed = rawPressed;

        // Przełącz LED tylko przy zaakceptowanym naciśnięciu.
        if (stablePressed) {
            ledOn = !ledOn;
            if (ledOn) {
                PORTB |= _BV(PORTB5);
            } else {
                PORTB &= ~_BV(PORTB5);
            }
        }
    }
}
