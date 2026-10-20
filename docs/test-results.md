# Wyniki testów — Offline Navigator

**Ostatnia aktualizacja:** 2026-10-20  
**Etap:** 2/9

## Zasady

Wynik rzeczywisty zapisujemy tylko wtedy, gdy został przekazany w logu lub jednoznacznie zgłoszony przez użytkownika. Przykłady edukacyjne nie są wynikami testów. Nie zapisujemy dokładnych współrzędnych użytkownika w portfolio.

## T2-01 — Odbiór surowych komunikatów NMEA (test z etapu 1)

- **Cel:** sprawdzić, czy Arduino otrzymuje transmisję tekstową z GPS.
- **Sprzęt:** Arduino UNO R3 / ATmega328P-PU; płytka opisana jako NEO-7M-0-000 compatible.
- **Połączenia:** GPS TX → D4 (RX SoftwareSerial), wspólne GND; GPS RX/PPS nieużywane. Wcześniej podano `SoftwareSerial(4, 3)`.
- **Program:** szkic z `SoftwareSerial` i `TinyGPSPlus`; osobny test surowego wypisywania NMEA został wcześniej uruchomiony.
- **Oczekiwany wynik:** linie NMEA widoczne w Monitorze portu szeregowego.
- **Rzeczywisty wynik:** w historycznych logach występowały komunikaty `GPGGA`, `GPGSA`, `GPGSV`, `GPGLL`, `GPRMC` i `GPVTG`; dane widoczne przy 115200 baud na Monitorze portu.
- **Wniosek:** odbiór UART i komunikaty NMEA były potwierdzone podczas testu z etapu 1.
- **Ograniczenie:** w przekazanym raporcie nie zachowano pełnej, konkretnej linii surowego NMEA do ponownego zacytowania. Przykładowe linie pokazane w późniejszych lekcjach były edukacyjne, nie były logiem tego urządzenia.

## T2-02 — Uzyskanie fixa na zewnątrz (test z etapu 1)

- **Cel:** potwierdzić, że odbiornik potrafi wyliczyć pozycję.
- **Program:** parser TinyGPSPlus.
- **Rzeczywisty wynik w historycznych logach:** `GGA quality=1`, `GSA fix type=3`, `RMC status=A`; w próbkach późniejszych 5–6 satelitów użytych do pozycji, w jednej próbce 6 użytych i 9 raportowanych przez GSV; HDOP około 1,49–1,50 w późniejszych logach oraz wcześniej HDOP 1,98, PDOP 2,51, VDOP 1,54. Odnotowano również `checksum_errors=0` w raportach programu.
- **Wniosek:** w poprzednich testach na zewnątrz uzyskano autonomiczny fix 3D.
- **Niezweryfikowane:** dokładność bezwzględna w metrach, porównanie do punktu referencyjnego, stabilność w lesie i przy budynkach, powtarzalność pomiarów.

## T2-03 — Brak fixa wewnątrz budynku (test z etapu 1)

- **Cel:** rozróżnić widoczność satelitów od wyliczenia pozycji.
- **Rzeczywisty wynik w historycznych logach:** `GGA quality=0`, 0 satelitów użytych do rozwiązania, `GSA fix type=1`, `RMC status=V`; mimo to GSV raportował część widocznych satelitów.
- **Wniosek:** odbiornik może widzieć/raportować sygnały satelitów, lecz nie mieć prawidłowego fixa. Sam brak fixa w pomieszczeniu nie dowodzi awarii odbiornika.

## T2-04 — Uproszczony program użytkownika wewnątrz domu (2026-10-19)

- **Cel:** zaobserwować zachowanie aktualnego programu przy braku pozycji.
- **Program:** kod wklejony przez użytkownika z `SoftwareSerial`, `TinyGPSPlus`, filtrem wykładniczym i warunkiem świeżości 3000 ms.
- **Parametry:** GPS UART 9600 baud; Serial Monitor 115200 baud; raport co 1000 ms; `FILTER_ALPHA=0.25`; `MAX_POSITION_AGE_MS=3000`.
- **Rzeczywisty wynik:** użytkownik przekazał kolejno:

  ```text
  20:25:13.900 -> FIX=NO | LAT=-- | LON=--
  20:25:14.899 -> FIX=NO | LAT=-- | LON=--
  20:25:15.898 -> FIX=NO | LAT=-- | LON=--
  20:25:16.902 -> FIX=NO | LAT=-- | LON=--
  ```

- **Wniosek:** program nie uważał pozycji za świeżą i ważną w tym teście wewnątrz domu.
- **Czego nie da się stwierdzić z tego logu:** czy w tej samej sesji dochodziły bajty UART, czy parser zatwierdzał komunikaty NMEA i czy brak fixa był jedyną przyczyną. Program nie drukował wówczas diagnostyki `CHARS`, `CK_OK`, `CK_BAD`.
- **Dalsze działanie:** brak kolejnych testów obecnego modułu zgodnie z decyzją użytkownika. Użytkownik kupi nowy odbiornik do docelowej płytki.

## T2-05 — Ręczna konwersja przykładowej współrzędnej

- **Cel:** zrozumieć format stopnie-minuty w NMEA.
- **Dane ćwiczeniowe:** `4807.038,N` — dane przykładowe, nie pomiar GPS użytkownika.
- **Wynik:** 48 stopni + 7,038 minuty / 60 = 48,1173° N.
- **Status:** poprawne rozwiązanie użytkownika.

## T2-06 — Ćwiczenie z walidacji pozycji

Użytkownik poprawnie ocenił trzy hipotetyczne przypadki: pozycja ważna, ale starsza od progu nie jest świeża; świeżość nie dowodzi dokładności; po utracie ważności starych współrzędnych nie należy pokazywać jako aktualnych.

## T2-07 — Ćwiczenie z diagnostyki komunikatów

Użytkownik poprawnie wskazał, że rosnący licznik znaków przy `CK_OK=0` i `CK_BAD=0` nie potwierdza jeszcze kompletnych komunikatów z sumą kontrolną; trzeba zbadać strumień/format, bez wnioskowania od razu o fixie.

## Testy nieprzeprowadzone / niezweryfikowane

- Szkic diagnostyczny z licznikami `charsProcessed()`, `passedChecksum()`, `failedChecksum()`, `sentencesWithFix()` i `SoftwareSerial.overflow()` został zaproponowany, ale użytkownik nie potwierdził jego wgrania ani uruchomienia.
- Brak dokładnej wersji Arduino IDE, Arduino AVR Boards/core, SoftwareSerial oraz TinyGPSPlus.
- Nie wykonano niezależnego pomiaru napięcia VCC, TX/RX ani jakości przebiegów oscyloskopem/analizatorem logicznym.
- Nie wykonano niezależnego pomiaru dokładności pozycji.
- Nie przeprowadzono nowego testu w lesie ani przy budynkach.

## Wersje narzędzi i bibliotek

| Element | Wersja/status |
|---|---|
| Arduino UNO R3 / ATmega328P-PU | Płytka zgłoszona jako używana; rewizja konkretnego klona/egzemplarza nieopisana |
| Arduino IDE | Wersja nieudokumentowana |
| Arduino AVR Boards/core | Wersja nieudokumentowana |
| `SoftwareSerial` | Używana; dokładna wersja zależna od core i nieudokumentowana |
| `TinyGPSPlus` | Używana; dokładna wersja nieudokumentowana |
| GPS firmware | Wersja nieudokumentowana |
