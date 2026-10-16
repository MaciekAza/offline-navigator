# Architektura systemu

**Status:** koncepcja; interfejsy i platforma docelowa nie zostały zatwierdzone.

## Główne bloki

```mermaid
flowchart LR
    GNSS[Odbiornik GNSS] --> MCU[Kontroler docelowy]
    MCU <--> SD[Karta microSD]
    MCU <--> DISP[Ekran]
    BTN[Przyciski] --> MCU
    COMP[Kompas — opcjonalnie] <--> MCU
    IMU[IMU / szacowanie ruchu — opcjonalnie] <--> MCU
    BAT[Akumulator] --> PWR[Układ zasilania]
    PWR --> MCU
    PWR --> GNSS
    PWR --> SD
    PWR --> DISP
```

Diagram przedstawia wyłącznie docelowe funkcje blokowe. Nie jest schematem elektrycznym ani instrukcją połączeń.

## Bloki funkcjonalne

| Blok | Rola | Status |
|---|---|---|
| GNSS | Pozycja, czas, prędkość i dane nawigacyjne | Moduł wstępnie opisany jako zgodny z NEO-7M; płytka i pinout do weryfikacji |
| Kontroler | Parsowanie danych GNSS, obsługa pamięci i interfejsu, renderowanie map | Nie wybrano platformy docelowej |
| Pamięć microSD | Lokalne mapy, punkty i zapis śladów | Czytnik niepotwierdzony w dostępnych komponentach |
| Ekran | Mapa i interfejs użytkownika | Dostępne LCD 16×2 i Grove LCD RGB; ekran mapowy do wyboru |
| Przyciski | Obsługa widoków i funkcji | Kilka przycisków THT dostępnych |
| Zasilanie | Konwersja napięć, zabezpieczenia i ładowanie | Architektura do zaprojektowania; brak potwierdzonego zestawu akumulatorowego |
| Kompas | Kierunek urządzenia, pomocniczo przy utracie GNSS | Funkcja opcjonalna, brak potwierdzonego modułu |
| IMU / dead reckoning | Krótkotrwałe szacowanie ruchu przy przerwanym GNSS | Koncepcja; dodatkowy sprzęt i ograniczenia do oceny |

## Decyzje, które trzeba podjąć przed projektem PCB

1. Wymagany obszar i szczegółowość map oraz format danych.
2. Wymagana rozdzielczość i przekątna ekranu.
3. Wybór kontrolera na podstawie RAM, Flash, interfejsów, wydajności i zużycia energii.
4. Wybór czytnika microSD i interfejsu komunikacyjnego.
5. Schemat zasilania, źródło energii, ładowanie i zabezpieczenia.
6. Złącza, sposób programowania, debugowania i aktualizacji firmware.

Nie zamrażaj projektu PCB, dopóki te decyzje nie będą uzasadnione.


## Wymaganie pracy przy słabym sygnale GNSS

Docelowo urządzenie ma być możliwie odporne na słaby odbiór w lesie i w pobliżu budynków. To wymaganie nie oznacza gwarancji fixa w pomieszczeniu: ściany, dachy i gęsta roślinność mogą blokować sygnał satelitarny. Rozważymy odbiornik wielokonstelacyjny oraz odpowiednią antenę i jej umiejscowienie. Przy utracie fixa interfejs powinien wyraźnie pokazywać brak aktualnej pozycji, zachować ostatnią znaną pozycję/ślad i — jeśli analiza potwierdzi sens — oferować krótkotrwałe przybliżenie ruchu z kompasu/IMU, z komunikatem o narastającej niepewności.
