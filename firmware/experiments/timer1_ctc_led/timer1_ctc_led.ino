// Offline Navigator — Timer1 w trybie CTC
// Arduino UNO R3 / ATmega328P, zegar nominalny 16 MHz.
// Compare Match A co 500 ms; ISR przełącza wbudowaną LED D13/PB5.
// Status: użytkownik potwierdził, że LED miga.
// Uwaga: przejmuje Timer1; może kolidować z Servo i PWM D9/D10.

#include <avr/interrupt.h>

void setup() {
    DDRB |= _BV(DDB5);        // PB5 / D13 jako wyjście
    PORTB &= ~_BV(PORTB5);    // LED początkowo zgaszona

    TCCR1A = 0;
    TCCR1B = 0;               // Zatrzymaj Timer1 na czas konfiguracji
    TCNT1 = 0;
    OCR1A = 31249;             // 31 250 taktów * 16 us = 500 ms

    TIFR1 = _BV(OCF1A);        // Skasuj starą flagę Compare Match A
    TIMSK1 |= _BV(OCIE1A);     // Włącz przerwanie Compare Match A

    TCCR1B |= _BV(WGM12);      // CTC, tryb 4
    TCCR1B |= _BV(CS12);       // Preskaler 256 (CS12:CS10 = 100)
}

void loop() {
    // Timer1 pracuje niezależnie od głównej pętli.
}

ISR(TIMER1_COMPA_vect) {
    PORTB ^= _BV(PORTB5);      // Zmień stan LED co 500 ms
}
