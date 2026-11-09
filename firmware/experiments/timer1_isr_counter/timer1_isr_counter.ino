// Offline Navigator — licznik przerwań Timer1 i bezpieczny odczyt
// Arduino UNO R3 / ATmega328P, zegar nominalny 16 MHz.
// Timer1 CTC: 10 ms (preskaler 64, OCR1A=2499).
// Status: kod i teoria omówione; użytkownik NIE potwierdził jeszcze
// uruchomienia tego osobnego szkicu i obserwacji Serial Monitora.

#include <avr/interrupt.h>
#include <util/atomic.h>

volatile uint16_t timerTicks = 0;
uint8_t ledDivider = 0; // używany wyłącznie w ISR

void setup() {
    DDRB |= _BV(DDB5);
    PORTB &= ~_BV(PORTB5);

    Serial.begin(115200);

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    OCR1A = 2499;              // 2500 taktów * 4 us = 10 ms

    TIFR1 = _BV(OCF1A);        // Skasuj starą flagę porównania
    TIMSK1 |= _BV(OCIE1A);     // Włącz Compare Match A

    TCCR1B = _BV(WGM12) | _BV(CS11) | _BV(CS10); // CTC, preskaler 64
}

ISR(TIMER1_COMPA_vect) {
    timerTicks++;

    ledDivider++;
    if (ledDivider >= 50) {
        ledDivider = 0;
        PORTB ^= _BV(PORTB5);  // LED zmienia stan co 500 ms
    }
}

void loop() {
    static unsigned long lastPrintMs = 0;
    const unsigned long now = millis();

    if (now - lastPrintMs >= 1000UL) {
        lastPrintMs = now;

        uint16_t snapshot;
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            snapshot = timerTicks;
        }

        Serial.print(F("Timer ticks: "));
        Serial.println(snapshot);
    }
}
