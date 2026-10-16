# Wyniki testów

Ten plik zbiera tylko testy istotne dla działania urządzenia. Nie jest dziennikiem każdej czynności ani miejscem na niezweryfikowane przewidywania.

## T-GNSS-001 — odbiór surowych komunikatów NMEA

**Status:** zaliczony w zakresie komunikacji szeregowej.

- Moduł: NEO-7M-0-000 compatible.
- Platforma: Arduino UNO R3.
- Wynik: odbierano czytelne zdania NMEA, m.in. GGA, GSA, GSV, GLL, RMC i VTG.
- Ograniczenie: sam odbiór NMEA nie potwierdza posiadania fixa.

## T-GNSS-002 — brak fixa wewnątrz budynku

**Status:** zaobserwowany wynik; test nie stanowi diagnozy uszkodzenia.

- GSV raportowało 4 satelity w komunikacie.
- GGA: jakość pozycji `0`, 0 satelitów użytych, HDOP `99.99`.
- GSA: typ fixa `1` (brak fixa).
- RMC/GLL: status nieważny (`V`).
- Wniosek: odbiornik raportował satelity, ale nie wyznaczał pozycji w tych warunkach.

## T-GNSS-003 — fix na otwartej przestrzeni

**Status:** zaliczony dla uzyskania fixa; dokładność niezweryfikowana.

- GGA quality `1`; GSA fix type `3`; RMC/GLL status `A`.
- W pierwszej zapisanej próbce: 4 satelity użyte, HDOP około `10.42`, PDOP około `15.30`, VDOP około `11.20`.
- Po około 3 minutach w kolejnej próbie: 6 satelitów użytych, 9 raportowanych w GSV, HDOP `1.98`, PDOP `2.51`, VDOP `1.54`.
- Wniosek: odbiornik uzyskał autonomiczny fix 3D na zewnątrz, a pod koniec dłuższej próby raportował korzystniejsze DOP.
- Ograniczenie: DOP nie jest bezpośrednim błędem w metrach. Nie przeprowadzono porównania z niezależnym punktem odniesienia.
- Prywatność: dokładnych współrzędnych z logu nie przechowujemy w portfolio.

## Następny sensowny test

Napisać własny parser NMEA, który raportuje status i świeżość fixa, współrzędne, liczbę satelitów oraz HDOP. Następnie przetestować go na otwartej przestrzeni i sprawdzić zachowanie w razie utraty sygnału.
