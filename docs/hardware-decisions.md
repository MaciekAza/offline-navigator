# Rejestr decyzji sprzętowych

Ten plik zbiera decyzje, które wpływają na architekturę. Nie jest dziennikiem codziennych ćwiczeń.

## HD-001 — Arduino UNO jako platforma eksperymentalna

**Status:** przyjęta tymczasowo.

**Decyzja:** wykorzystać posiadane UNO do testów podstawowych obwodów, GPIO, UART i prototypów peryferiów. Nie zakładać, że będzie kontrolerem końcowym nawigacji.

**Uzasadnienie:** ATmega328P w UNO R3 ma 32 KB Flash i 2 KB SRAM. To bardzo mało dla obsługi ekranu i buforów mapowych. Ostateczny wybór trzeba oprzeć o format map, ekran, wymagania wydajnościowe i budżet energetyczny.

**Źródło:** [Arduino UNO R3 — oficjalna specyfikacja](https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf).

## HD-002 — GPS bez zasilania do czasu identyfikacji breakout boardu

**Status:** otwarta weryfikacja; zasada bezpieczeństwa obowiązuje.

**Decyzja:** nie podłączać jeszcze modułu GPS do Arduino.

**Uzasadnienie:** oznaczenie „NEO-7M compatible” nie potwierdza, czy konkretna płytka ma regulator napięcia i konwertery poziomów logicznych. Dokumentacja samego modułu NEO-7M podaje zasilanie VCC 1,65–3,6 V; nie wolno automatycznie przenosić tych parametrów na gotową płytkę pośredniczącą ani zakładać tolerancji na sygnały 5 V.

**Następny krok:** obejrzeć obie strony modułu i oznaczenia pinów, zidentyfikować dokładny model płytki, a następnie znaleźć dokumentację producenta lub wiarygodny schemat.

**Źródło:** [u-blox NEO-7 — datasheet](https://content.u-blox.com/sites/default/files/products/documents/NEO-7_DataSheet_%28UBX-13003830%29.pdf) i [strona serii NEO-7](https://www.u-blox.com/en/product/neo-7-series).

## HD-003 — nie zamrażać jeszcze ekranu

**Status:** otwarta.

**Decyzja:** używane LCD 16×2 i Grove RGB można wykorzystać do prób UI/diagnostyki, ale nie uznawać ich za docelowy ekran mapy.

**Uzasadnienie:** interfejs, rozdzielczość, widoczność na zewnątrz, sterownik, RAM i pobór mocy muszą pasować do renderowania map.

## HD-004 — nie wybierać jeszcze akumulatora

**Status:** otwarta.

**Decyzja:** najpierw oszacować i zmierzyć pobór prądu bloków, ustalić wymagany czas pracy i napięcia wszystkich elementów. Dopiero potem dobrać ogniwo, ładowanie, ochronę i przetwornice.

## HD-005 — nie kupować czytnika microSD ani kompasu przed ustaleniem wymagań

**Status:** otwarta.

**Decyzja:** kupować dodatkowe moduły, gdy będą potrzebne do wybranego prototypu i znane będą wymagania elektryczne oraz interfejsy.
