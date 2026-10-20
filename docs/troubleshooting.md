# Troubleshooting — Offline Navigator

**Ostatnia aktualizacja:** 2026-10-20

## 1. `FIX=NO` wewnątrz domu

**Zaobserwowane:** w teście z 2026-10-19 program wyświetlał kilka razy `FIX=NO | LAT=-- | LON=--`.

**Interpretacja:** kod wyświetla `FIX=NO`, gdy lokalizacja nie jest uznana za ważną/świeżą albo filtr nie został zainicjalizowany. Sam ten komunikat nie rozróżnia braku fixa od braku odbioru UART.

**Kontekst historyczny:** w teście z etapu 1 również zgłoszono brak fixa wewnątrz pomieszczenia; na zewnątrz uzyskano fix 3D.

**Nie wolno wnioskować:** że moduł jest zepsuty wyłącznie na podstawie `FIX=NO` wewnątrz budynku.

**Decyzja projektu:** użytkownik nie chce dalej testować starego modułu i planuje kupić nowy odbiornik. Nie wracać do powtarzania tego testu, chyba że później pojawi się konkretna potrzeba diagnostyczna.

## 2. Brak komunikatów na Serial Monitorze

Jeżeli taki problem wystąpi w przyszłości, sprawdzić osobno:

1. Czy Serial Monitor jest ustawiony na 115200 baud dla `Serial.begin(115200)`.
2. Czy `gpsSerial.begin(9600)` odpowiada szybkości wyjściowej nowego odbiornika.
3. Czy TX odbiornika trafia do RX portu Arduino; np. przy `SoftwareSerial gpsSerial(4, 3)` RX Arduino jest na D4.
4. Czy urządzenia mają wspólną masę.
5. Czy zasilanie modułu oraz jego poziomy logiczne odpowiadają dokładnej dokumentacji płytki.
6. Czy program regularnie opróżnia bufor wejściowy i nie wykonuje długich, blokujących operacji.

To lista możliwych przyczyn, a nie ustalenie, że któraś z nich wystąpiła w tym projekcie.

## 3. Znaki docierają, lecz brak potwierdzonych komunikatów NMEA

W przyszłej diagnostyce interpretować łącznie:

- `gps.charsProcessed()` — liczbę znaków przekazanych parserowi;
- `gps.passedChecksum()` — liczbę zdań z poprawną sumą kontrolną;
- `gps.failedChecksum()` — liczbę zdań z niepoprawną sumą kontrolną;
- `gpsSerial.overflow()` — czy wystąpiło przepełnienie bufora SoftwareSerial (wywołanie odczytuje i czyści flagę przepełnienia w implementacji Arduino AVR).

Jeżeli licznik znaków rośnie, ale liczniki sum kontrolnych pozostają zerowe, nie dowodzi to samo w sobie konkretnej awarii. Możliwe, że nie odebrano jeszcze całego zdania, format jest inny albo parser nie widzi kompletnego komunikatu.

Jeżeli błędy sum kontrolnych rosną, możliwe przyczyny to utrata/zmiana znaków, niewłaściwa szybkość transmisji albo zakłócenia. Sam licznik nie identyfikuje przyczyny.

Dokumentacja:
- TinyGPSPlus API: https://github.com/mikalhart/TinyGPSPlus/blob/master/src/TinyGPS%2B%2B.h
- TinyGPSPlus parser: https://github.com/mikalhart/TinyGPSPlus/blob/master/src/TinyGPS%2B%2B.cpp
- Arduino `SoftwareSerial.overflow()`: https://docs.arduino.cc/learn/built-in-libraries/software-serial/

## 4. Brak fixa a brak transmisji

Nie utożsamiać tych przypadków:

- **Brak fixa:** odbiornik może wysyłać poprawne NMEA, ale komunikaty wskazują brak ważnej pozycji.
- **Brak transmisji:** Arduino nie otrzymuje znaków albo nie przekazuje ich parserowi.
- **Niepoprawne zdania:** znaki są odbierane, ale komunikaty nie przechodzą kontroli sumy lub nie mają oczekiwanego formatu.
- **Pozycja stara:** parser zachował ostatnią poprawną lokalizację, lecz jej wiek przekracza przyjęty próg.

## 5. Filtr pozycji

Obecny prototyp stosuje filtr wykładniczy z `FILTER_ALPHA=0.25`. Wygładza on zmiany kolejnych współrzędnych, ale nie zwiększa automatycznie dokładności bezwzględnej. Może opóźniać pozycję podczas ruchu. Po przerwie, gdy pozycja przestaje być świeża, program wyzerowuje flagę `filterInitialized`, żeby kolejną zaakceptowaną pozycję wykorzystać jako nowy punkt startowy filtra.

## 6. Bezpieczeństwo nowego modułu i PCB

Nie podłączać nowej płytki wyłącznie na podstawie nazwy odbiornika GNSS. Weryfikować osobno:

- zakres zasilania VCC płytki;
- logikę napięć TX/RX;
- czy płytka ma regulator i konwerter poziomów;
- dopuszczalne napięcie na RX odbiornika;
- pobór prądu i antenę;
- pinout konkretnego wariantu.

Wcześniejsze użycie 5 V zostało zgłoszone przez użytkownika, ale napięcie przy module nie zostało zapisane jako pomiar. Zgodność z dokumentacją podobnej płytki Waveshare nie jest dowodem identyczności klona.
