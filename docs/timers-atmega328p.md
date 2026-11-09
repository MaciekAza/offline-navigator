# Timery ATmega328P — Timer0, Timer1, CTC i ISR

**Platforma:** Arduino UNO R3 / ATmega328P, zegar nominalny 16 MHz.

## Timer0 i `millis()`

W standardowym Arduino AVR core Timer0 jest używany do odmierzania czasu i PWM na pinach D5/D6. Przy typowej konfiguracji UNO pracuje z preskalerem 64:

- 16 MHz / 64 = 250 kHz,
- takt timera = 4 µs,
- Timer0 jest 8-bitowy: przepełnia się po 256 taktach,
- 256 × 4 µs = 1,024 ms.

Przerwanie przepełnienia aktualizuje programowe liczniki czasu. `millis()` odczytuje ten licznik; nie jest osobnym timerem sprzętowym. Nie rekonfiguruj Timer0 bez zrozumienia wpływu na `millis()`, `micros()`, `delay()` i PWM D5/D6.

## Timer1 w trybie CTC — LED D13 co 500 ms

Szkic: `firmware/experiments/timer1_ctc_led/timer1_ctc_led.ino`.

- Timer1 jest 16-bitowy.
- Tryb CTC: `WGM12=1`, pozostałe bity WGM ustawione na 0 (mode 4).
- Preskaler 256: `CS12:CS10 = 100`.
- Częstotliwość timera: 16 MHz / 256 = 62 500 Hz.
- Takt: 16 µs.
- `OCR1A=31249`, więc okres porównania: (31249+1) × 16 µs = 500 ms.
- `TIMSK1.OCIE1A` zezwala na przerwanie Compare Match A.
- `ISR(TIMER1_COMPA_vect)` przełącza PB5/LED D13.

Użytkownik potwierdził, że LED miga. Okres nie był niezależnie zmierzony oscyloskopem ani analizatorem logicznym.

## Licznik przerwań co 10 ms — kod edukacyjny

Szkic: `firmware/experiments/timer1_isr_counter/timer1_isr_counter.ino`.

- Preskaler 64: 16 MHz / 64 = 250 kHz, takt 4 µs.
- `OCR1A=2499`: (2499+1) × 4 µs = 10 ms.
- ISR inkrementuje `volatile uint16_t timerTicks`.
- `loop()` pobiera spójny snapshot w `ATOMIC_BLOCK(ATOMIC_RESTORESTATE)`.
- `Serial.print()` odbywa się w `loop()`, a nie w ISR.

**Status:** kod i zasady zostały omówione, ale użytkownik nie potwierdził uruchomienia tego osobnego szkicu ani wartości w Monitorze portu szeregowego.

## `volatile` i atomowość

`volatile` zapobiega traktowaniu obiektu jako niezmiennego przez optymalizator, gdy jego wartość może być zmieniana asynchronicznie (np. przez ISR). Nie gwarantuje atomowości. Na 8-bitowym AVR odczyt `uint16_t` może wymagać pobrania dwóch bajtów; ISR może wystąpić między nimi. Krótki `ATOMIC_BLOCK` chroni spójny odczyt.

## Ograniczenia ISR

ISR powinna być krótka. Nie należy wykonywać w niej rozbudowanego parsowania GPS, długich opóźnień ani wypisywania przez `Serial`. Długie ISR opóźniają obsługę innych przerwań i mogą prowadzić do utraty danych.

## Konflikty zasobów

Eksperymenty Timer1 przejmują Timer1. Mogą kolidować z bibliotekami używającymi Timer1 (np. Servo) oraz z typowym PWM na D9/D10. Nie uruchamiaj ich równolegle z innym szkicem ani nie traktuj ich jako gotowej konfiguracji finalnego firmware.
