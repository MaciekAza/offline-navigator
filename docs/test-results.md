# Wyniki testów

Ten dokument zawiera wyłącznie testy powiązane z funkcjami urządzenia, decyzjami projektowymi lub bezpieczeństwem. Nie zapisujemy tu każdego ćwiczenia edukacyjnego.

## Status testów

| ID | Test | Co ma potwierdzić | Status | Dowód |
|---|---|---|---|---|
| T-001 | Identyfikacja płytki GPS | Dokładne oznaczenia płytki, pinout oraz możliwość ustalenia toru zasilania/poziomów logicznych | W toku — potrzebne zdjęcia obu stron i pinów | Brak |
| T-002 | Komunikacja GNSS przez UART | Otrzymywanie poprawnych komunikatów NMEA przy zgodnych poziomach elektrycznych | Nie rozpoczęto | Brak |
| T-003 | Zapis/odczyt na microSD | Powtarzalny zapis i odczyt pliku testowego | Nie rozpoczęto | Brak; czytnik do wyboru |
| T-004 | Interfejs ekranu | Poprawne wyświetlanie danych pozycji i podstawowego UI | Nie rozpoczęto | Brak |
| T-005 | Budżet energetyczny | Pobór prądu i oszacowanie czasu pracy docelowej konfiguracji | Nie rozpoczęto | Brak |
| T-006 | Pierwsza rewizja PCB | Kontrola zasilania, zwarć i interfejsów przed pełną integracją | Nie rozpoczęto | Brak; PCB nie zaprojektowano |

## Wymagany format wpisu po zakończeniu ważnego testu

- **ID i nazwa:**
- **Cel / wymaganie:**
- **Konfiguracja:** wersje modułów, firmware, źródło zasilania i ustawienia.
- **Procedura:** kroki pozwalające powtórzyć test.
- **Oczekiwany wynik:**
- **Wynik rzeczywisty:** wyłącznie faktycznie zaobserwowane dane.
- **Kryterium zaliczenia:**
- **Wynik:** zaliczony / niezaliczony / nierozstrzygnięty.
- **Dowody:** log, zdjęcie, zrzut ekranu lub dane pomiarowe.
- **Ograniczenia i uwagi:**

Nie wpisywać przewidywanych wartości w polu wyniku rzeczywistego.
