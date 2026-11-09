# ATmega328P GPIO: DDRB, PORTB i maski bitowe

**Kontekst:** Offline Navigator — eksperymenty etapu 3/9  
**Platforma:** Arduino UNO R3 / ATmega328P

## Mapowanie użyte w ćwiczeniach

- Arduino D12 = ATmega328P PB4.
- Arduino D13 = ATmega328P PB5 (wbudowana LED na typowym UNO R3).
- Arduino D4 = ATmega328P PD4 — to nie jest PB4.
- Arduino D2 = ATmega328P PD2 / INT0.

Numer Arduino i numer bitu portu AVR to różne oznaczenia. D12 jest bitem 4 portu B, nie bitem 12.

## Rejestry

- `DDRB`: kierunek pinów portu B; bit `1` = wyjście, bit `0` = wejście.
- `PORTB`: dla wyjścia ustala LOW/HIGH; dla wejścia bit `1` włącza wewnętrzny pull-up.
- `PINB`: odczytuje fizyczny stan pinów portu B.
- Analogicznie dla portu D używa się `DDRD`, `PORTD` i `PIND`.

## `|=` i `_BV()`

```cpp
DDRB |= _BV(DDB5);
```

`_BV(DDB5)` tworzy maskę `00100000`. Operator `|=` jest równoważny `DDRB = DDRB | maska`; ustawia bit 5 i zachowuje pozostałe bity.

```text
  00100000
| 00000100
----------
  00100100
```

Przykład sprawdzony w zadaniu rachunkowym:

```cpp
DDRB  = 00100000;
PORTB = 00100000;
DDRB |= _BV(DDB2);
PORTB |= _BV(PORTB2);
```

Wynik: `DDRB = 00100100`, `PORTB = 00100100`. Bit 5 pozostaje ustawiony, bo OR z maską bitu 2 go nie kasuje.

Aby wyzerować wyłącznie bit 5:

```cpp
PORTB &= ~_BV(PORTB5);
```

## Potwierdzone ćwiczenia

- Użytkownik potwierdził miganie wbudowanej LED D13 sterowanej bezpośrednio przez `DDRB` i `PORTB`.
- Użytkownik używał przycisku na D12/PB4 z wewnętrznym pull-up.
- Użytkownik potwierdził działanie programowego debounce opartego na `millis()` i progu 30 ms.

Rozwiązanie rachunkowe potwierdza rozumienie masek; nie jest samo w sobie dowodem testu sprzętowego.
