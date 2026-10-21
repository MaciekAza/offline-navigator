# ATmega328P GPIO: DDRB, PORTB i maski bitowe

**Kontekst:** Offline Navigator — materiał referencyjny etapu 3/9  
**Platforma:** Arduino UNO R3 / ATmega328P  
**Status:** teoria sprawdzona w ćwiczeniach; uruchomienie GPIO na fizycznej płytce nie zostało jeszcze potwierdzone.

## Rola rejestrów

- `DDRB`: kierunek pinów portu B. Bit `1` konfiguruje odpowiedni pin jako wyjście, bit `0` jako wejście.
- `PORTB`: dla pinu skonfigurowanego jako wyjście ustawia stan niski/wysoki. Dla wejścia może sterować wewnętrznym rezystorem podciągającym.
- `PINB`: odczytuje fizyczne stany pinów portu B.
- Na Arduino UNO R3 pin D13 mapuje się na PB5.

## Co robi `|=`?

```cpp
DDRB |= _BV(DDB5);
```

`_BV(DDB5)` tworzy maskę z ustawionym wyłącznie bitem 5, czyli `00100000`. Operator `|=` wykonuje OR z obecną wartością rejestru i zapisuje wynik. Pozwala ustawić wskazany bit bez kasowania pozostałych bitów.

```text
  00000000
| 00100000
----------
  00100000
```

Następnie:

```cpp
PORTB |= _BV(PORTB5);
```

ustawia bit 5 rejestru `PORTB`. Jeżeli `DDRB5` jest już ustawiony na 1, pin PB5 jest wyjściem i przechodzi w stan wysoki — w typowym Arduino UNO powoduje to zaświecenie wbudowanej diody D13.

Pierwsza instrukcja wybiera tryb pinu (wejście/wyjście); druga ustawia stan wyjścia. Nie są to dwa polecenia zapalające LED.

## Przykład sprawdzony w ćwiczeniu obliczeniowym

Stan początkowy:

```text
DDRB  = 00100000
PORTB = 00100000
```

Kod:

```cpp
DDRB |= _BV(DDB2);
PORTB |= _BV(PORTB2);
```

Maska bitu 2 wynosi `00000100`. Zastosowanie OR:

```text
  00100000
| 00000100
----------
  00100100
```

Wyniki końcowe:

- `DDRB = 00100100`
- `PORTB = 00100100`
- Bit 5 pozostał ustawiony na 1, ponieważ OR z maską bitu 2 nie kasuje bitu 5.

Użytkownik poprawnie podał oba rejestry oraz uzasadnił, że bit 5 pozostaje ustawiony, bo `|=` nie nadpisuje całego rejestru zerami/nową maską.

## Kasowanie pojedynczego bitu

Aby wyzerować wybrany bit bez zmiany pozostałych, można użyć:

```cpp
PORTB &= ~_BV(PORTB5);
```

`~` odwraca maskę, a `&=` zachowuje wszystkie bity poza wskazanym bitem, który zostaje wyzerowany.

## Ważne rozróżnienie statusu

Poprawne rozwiązanie obliczenia binarnego potwierdza rozumienie konkretnej operacji logicznej. Nie jest dowodem na to, że kod skompilował się lub został wgrany na Arduino. Fizyczny test LED należy oznaczyć jako wykonany dopiero po potwierdzeniu przez użytkownika.
