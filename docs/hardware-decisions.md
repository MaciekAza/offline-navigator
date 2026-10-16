# Rejestr decyzji sprzętowych

Ten dokument zawiera decyzje wpływające na architekturę urządzenia, nie dziennik codziennych ćwiczeń.

## HD-001 — Arduino UNO jako platforma eksperymentalna

**Status:** przyjęta tymczasowo.

**Decyzja:** używać posiadanego UNO do testów GPIO, UART, peryferiów i podstaw firmware. Nie uznawać go za docelowy kontroler map offline.

**Uzasadnienie:** ATmega328P w UNO R3 ma 32 KB Flash i 2 KB SRAM, co jest poważnym ograniczeniem przy renderowaniu map i buforowaniu danych. Ostateczny wybór musi wynikać z formatu map, ekranu, interfejsów i budżetu energetycznego.

**Dokumentacja:** [Arduino UNO R3 — oficjalna specyfikacja](https://docs.arduino.cc/hardware/uno-rev3/).

## HD-002 — obecny moduł GNSS jest platformą do testów, nie finalnym wyborem

**Status:** tymczasowo przyjęta.

**Potwierdzone z opisu i testów:** odbiornik na płytce oznaczonej `NEO-7M-0-000 compatible`; wyprowadzenia opisane jako PPS/RX/TX/GND/VCC; Arduino odbiera NMEA z GPS TX podłączonego do D4.

**Niepotwierdzone:** dokładna wersja płytki pośredniczącej, model i typ anteny, zakres wejścia VCC całej płytki oraz odporność RX na poziom 5 V. W testach zachowano działającą konfigurację zasilania, ale nie wolno na tej podstawie automatycznie przenosić tego połączenia na inną płytkę.

**Wyniki:** fix 3D uzyskano na otwartej przestrzeni. Późniejsze próbki raportowały 5–6 satelitów użytych i HDOP ok. 1,49–1,50. Dokładność bezwzględna nie została zmierzona.

**Decyzja:** korzystać z NEO-7M w prototypie do nauki UART/NMEA; przed finalną PCB porównać współczesne wielokonstelacyjne odbiorniki, anteny, wymagania zasilania, pobór energii i dostępność dokumentacji.

**Dokumentacja:** [u-blox NEO-7 series](https://www.u-blox.com/en/product/neo-7-series), [u-blox M10 series](https://www.u-blox.com/en/product/ubx-m10-series).

## HD-003 — odbiór w trudnych warunkach

**Status:** wymaganie projektowe przyjęte; realizacja sprzętowa otwarta.

**Wymaganie:** maksymalizować dostępność i stabilność pozycji w gęstym lesie oraz w pobliżu budynków. Nie gwarantujemy fixa wewnątrz dowolnego budynku ani pod każdą koroną drzew.

**Kierunek:** porównać nowoczesny odbiornik wielokonstelacyjny, właściwą antenę/umiejscowienie i zakłócenia generowane przez resztę płytki. UI powinien jawnie sygnalizować brak aktualnej pozycji. Kompas/IMU można ocenić jako pomocniczy fallback, z narastającą niepewnością.

## HD-004 — ekran pozostaje niezdecydowany

**Status:** otwarta.

Dostępne LCD 16×2 i Grove RGB można wykorzystać do komunikatów diagnostycznych, ale nie zostały wybrane jako ekran mapy. Wybór finalny zależy od widoczności w słońcu, rozdzielczości, interfejsu, sterownika, pamięci i poboru mocy.

## HD-005 — zasilanie i microSD bez decyzji zakupowej

**Status:** otwarta.

Przed wyborem akumulatora trzeba zmierzyć/ oszacować pobór prądu bloków, ustalić wymagany czas pracy, napięcia i układ ładowania/ochrony. Czytnik microSD nie został jeszcze potwierdzony; dodatkowe elementy kupować dopiero po zdefiniowaniu wymagań.
