# Offline Navigator

Projekt przenośnej nawigacji GPS działającej bez internetu. Celem jest zaprojektowanie urządzenia obejmującego odbiornik GNSS, lokalne mapy OpenStreetMap, ekran, obsługę przycisków, zapis punktów i śladów na karcie microSD oraz zasilanie akumulatorowe. Projekt ma również obejmować własny schemat i płytkę PCB zaprojektowane w KiCad.

> **Status: prototypowanie i nauka projektowania sprzętu.** Odbiór komunikatów NMEA z modułu NEO-7M i uzyskanie pierwszego fixa na otwartej przestrzeni zostały potwierdzone w testach. Firmware nawigacji nie został jeszcze napisany.

## Cele projektu

- [x] Zidentyfikować podstawowe wyposażenie i rozpocząć weryfikację modułu GNSS.
- [x] Odebrać surowe komunikaty NMEA z odbiornika GPS przez Arduino UNO.
- [x] Potwierdzić fix 3D na otwartej przestrzeni w teście prototypowym.
- [ ] Napisać własny parser danych GNSS i raport diagnostyczny.
- [ ] Zmierzyć stabilność pozycji i opisać ograniczenia obecnego odbiornika.
- [ ] Zdecydować o docelowym mikrokontrolerze i ekranie dla map offline.
- [ ] Dodać odczyt mapy offline, obsługę ekranu i nawigację po menu.
- [ ] Dodać zapis punktów i śladów na microSD.
- [ ] Zaprojektować układ zasilania i ocenić czas pracy z akumulatora.
- [ ] Przygotować schemat oraz PCB w KiCad.
- [ ] Zbudować obudowę i przeprowadzić testy końcowe.

## Aktualne stanowisko prototypowe

- Arduino UNO R3 z ATmega328P-PU
- Moduł GNSS oznaczony NEO-7M-0-000 compatible
- Odbiór danych GPS przez UART/SoftwareSerial podczas testu
- Pozostałe dostępne komponenty wymieniono w [inwentaryzacji sprzętu](docs/hardware-inventory.md)

Arduino UNO służy obecnie do nauki i testów komunikacji. Nie jest jeszcze zatwierdzony jako docelowa platforma dla renderowania map offline. Przed wyborem finalnego mikrokontrolera należy określić format map, wymagania ekranu, pamięć potrzebną na dane oraz budżet energetyczny.

## Wymaganie dotyczące odbioru w trudnych warunkach

Celem projektu jest możliwie dobra dostępność pozycji w gęstym lesie oraz w pobliżu i wewnątrz budynków. Będzie to wymaganie do sprawdzenia w porównywalnych testach, a nie obietnica stałego fixa GPS. Jeśli sygnał GNSS będzie niedostępny, urządzenie powinno jasno sygnalizować utratę fixa. Można później ocenić dodatkowe źródła informacji, takie jak kompas i IMU, pamiętając, że estymacja ruchu bez GNSS narasta błędem.

## Dokumentacja

- [Architektura](docs/architecture.md)
- [Inwentaryzacja sprzętu](docs/hardware-inventory.md)
- [Decyzje sprzętowe](docs/hardware-decisions.md)
- [Wyniki testów](docs/test-results.md)
- [Rozwiązywanie problemów](docs/troubleshooting.md)

## Zasada dokumentowania

Repozytorium jest portfolio projektu, a nie dziennikiem każdej lekcji. Trafiają tu istotne decyzje, kod, schematy, wyniki testów bloków urządzenia i problemy, których rozwiązanie wpływa na projekt. Wyniki pomiarów należy opisywać jako rzeczywiste tylko wtedy, gdy zostały wykonane i zapisane.
