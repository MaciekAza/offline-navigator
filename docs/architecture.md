# Architektura systemu

## Cel

Przenośna nawigacja GNSS z mapami przechowywanymi lokalnie, zaprojektowana do pracy bez dostępu do internetu.

## Bloki funkcjonalne

1. **GNSS** — odbiór pozycji, czasu, prędkości i statusu fixa.
2. **Mikrokontroler** — sterowanie urządzeniem, walidacja danych oraz logika nawigacji.
3. **Mapa offline** — dane mapowe zapisane lokalnie i przygotowane przed użyciem urządzenia.
4. **Ekran i interfejs** — prezentowanie mapy, pozycji, statusu GNSS i menu obsługi.
5. **Pamięć masowa** — karta microSD do map, punktów i śladów, zależnie od przyjętej architektury.
6. **Wejście użytkownika** — przyciski, a ewentualnie także enkoder.
7. **Zasilanie** — akumulator, ładowanie, zabezpieczenia i stabilizacja napięć.
8. **Opcjonalne czujniki** — kompas i/lub IMU do wspomagania orientacji w ograniczonym zakresie, jeśli testy wykażą sens takiego rozwiązania.

## Aktualny prototyp

Arduino UNO R3 komunikuje się z modułem opisanym NEO-7M-0-000 compatible. Odebrano komunikaty NMEA, a następnie zaobserwowano fix 3D na otwartej przestrzeni. Nie napisano jeszcze docelowego parsera ani interfejsu użytkownika.

## Decyzje otwarte

- Docelowy mikrokontroler, pamięć RAM/Flash i sposób renderowania map.
- Format map offline oraz narzędzie do ich przygotowania.
- Rodzaj i rozdzielczość ekranu.
- Czy obecny GNSS i antena spełniają wymagania terenowe.
- Czy wymagany jest kompas/IMU i w jaki sposób sygnalizować tryb szacowanej pozycji.
- Architektura zasilania, akumulator i docelowy czas pracy.
- Interfejs karty microSD i organizacja przechowywanych danych.
