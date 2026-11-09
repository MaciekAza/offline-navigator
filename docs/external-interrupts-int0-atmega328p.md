# Przerwanie zewnętrzne INT0 — ATmega328P

**Platforma:** Arduino UNO R3 / ATmega328P  
**Eksperyment:** przycisk między D2/PD2/INT0 a GND; wbudowana LED D13/PB5.

## Mapowanie i połączenie

- Arduino D2 = ATmega328P PD2 = INT0.
- Arduino D13 = ATmega328P PB5 = wbudowana LED.
- Wewnętrzny pull-up utrzymuje zwolniony przycisk w stanie HIGH; naciśnięcie zwiera wejście do GND i daje LOW.

## Rejestry

- `DDRD`: konfiguruje PD2 jako wejście.
- `PORTD`: przy PD2 jako wejściu włącza pull-up.
- `EICRA`: wybiera warunek wyzwalania INT0 przez `ISC01:ISC00`.
- `EIMSK.INT0`: zezwala na obsługę źródła INT0.
- `EIFR.INTF0`: flaga zdarzenia INT0, kasowana przez zapis jedynki (W1C).
- `SREG.I`: globalne zezwolenie na przerwania; `sei()` ustawia bit I.

## `ISC01:ISC00`

| Bity | Warunek | Dla przycisku pull-up |
|---|---|---|
| `00` | niski poziom | żądanie aktywne, gdy wejście pozostaje LOW |
| `01` | dowolna zmiana | naciśnięcie i zwolnienie |
| `10` | zbocze opadające | naciśnięcie HIGH→LOW |
| `11` | zbocze narastające | zwolnienie LOW→HIGH |

## Flaga a maska przerwania

Zdarzenie może ustawić `EIFR.INTF0`, nawet gdy `EIMSK.INT0` jest wyłączony. Wykonanie wektora ISR wymaga zezwolenia w `EIMSK` oraz globalnego bitu `SREG.I`.

`EIFR` używa semantyki write-one-to-clear. Kasuj wybraną flagę przez przypisanie, np. `EIFR = _BV(INTF0)`. Nie stosuj bezmyślnie `EIFR |= _BV(INTF0)`, ponieważ read-modify-write może skasować również inne flagi odczytane jako jedynki.

## Ograniczenia demonstracyjnego szkicu

`buttonEvent` jest flagą `bool`. Kilka zdarzeń przed obsłużeniem może zlać się w jedno. Drgania styków mogą wygenerować kilka zboczy na jedno naciśnięcie. Szkic demonstruje INT0, ale nie jest odpornym licznikiem naciśnięć i nie zawiera debounce.

## Wynik użytkownika

- Potwierdzono sprzętowo, że naciśnięcie przycisku zmienia stan LED.
- Przytrzymanie przez około 3 sekundy dawało jedno przełączenie — zgodne z wyzwalaniem zboczem opadającym.
- Szybkie naciśnięcia dawały nieregularne zachowanie / miganie; jest to zgodne z brakiem debounce i z użyciem pojedynczej flagi `bool`.
- Użytkownik poprawnie rozróżnił mapowanie D2→PD2 oraz sens trybu `10`; skorygowano jego sugestię, że `01` oznacza samo zwolnienie (w rzeczywistości oznacza dowolną zmianę; samo zwolnienie to `11`).
