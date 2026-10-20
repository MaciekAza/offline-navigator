# Decyzje sprzętowe — Offline Navigator

**Ostatnia aktualizacja:** 2026-10-20  
**Etap:** 2/9 — odbiornik GPS, UART i NMEA

## Status i poziom pewności

W tym dokumencie rozróżniamy:
- **Potwierdzone w logu** — istnieje rzeczywisty wynik lub log z testu.
- **Zgłoszone przez użytkownika** — informacja podana przez użytkownika, bez niezależnego pomiaru.
- **Zgodne z dokumentacją podobnej płytki** — dane producenta odpowiadającej konstrukcji, ale nie dowód tożsamości egzemplarza.
- **Niezweryfikowane** — nie ma wystarczających danych.

## 1. Płytka GPS

- **Oznaczenie odbiornika widoczne na zdjęciu:** `NEO-7M-0-000 COMPATIBLE`.
- **Oznaczenia płytki widoczne na zdjęciu:** `WaveShare` oraz `NEO-6M/7M GPS` (odczyt ze zdjęć przekazanych w rozmowie).
- **Opis pinów:** `VCC`, `GND`, `TX`, `RX`, `PPS`.
- **Antena:** zewnętrzny element antenowy połączony przewodem; dokładny model anteny nieustalony.
- **Identyfikacja:** konstrukcja wygląda na zgodną z rodziną Waveshare UART GPS NEO-7M-C (B), ale producent, oryginalność, rewizja PCB i dokładny wariant odbiornika pozostają **niezweryfikowane**.
- **Decyzja użytkownika:** obecny moduł nie będzie dalej testowany; użytkownik planuje kupić nowy odbiornik do docelowej płytki.

Oficjalna dokumentacja odpowiadającej płytki Waveshare podaje zasilanie VCC 2,7–5,0 V, deklarowaną zgodność TTL z systemami 3,3 V i 5 V, transmisję 9600 baud oraz prąd roboczy 35 mA. Są to dane **dla udokumentowanej płytki Waveshare**, a nie potwierdzone parametry konkretnego egzemplarza: https://www.waveshare.com/wiki/UART_GPS_NEO-7M-C oraz https://www.waveshare.com/uart-gps-neo-7m-c-b.htm.

Karta katalogowa samego modułu u-blox NEO-7M podaje VCC 1,65–3,6 V: https://content.u-blox.com/sites/default/files/products/documents/NEO-7_DataSheet_%28UBX-13003830%29.pdf. Nie wolno utożsamiać wymagań samego układu z możliwościami płytki nośnej. Również nie wolno automatycznie przenosić danych płytki Waveshare na dowolną płytkę „compatible”.

## 2. Zasilanie i poziomy logiczne

- **Zgłoszone przez użytkownika:** w poprzednim teście moduł był zasilany z pinu 5V Arduino UNO.
- **Rzeczywisty pomiar napięcia na VCC:** nie wykonano lub nie zapisano.
- **Tolerancja wejścia RX konkretnej płytki:** niezweryfikowana.
- **Dokładna topologia regulatora i konwerterów poziomów:** niezweryfikowana.
- W testach odbiorczych pin GPS RX nie był używany, a zatem Arduino nie wysyłało danych do wejścia RX modułu.

**Decyzja projektowa:** przed podłączeniem nowego modułu oraz przed zaprojektowaniem PCB sprawdzić dokumentację dokładnego modułu/breakout boardu, zakres VCC, napięcia logiczne TX/RX, pobór prądu i wymagania anteny. Nie opierać projektu PCB tylko na nazwie układu odbiornika.

## 3. Połączenia używane w prototypie

Opis konfiguracji z wcześniejszych testów, nie zalecenie do niezweryfikowanego nowego modułu:

```text
GPS TX  -> Arduino UNO D4 (SoftwareSerial RX)
GPS GND -> Arduino UNO GND
GPS VCC -> Arduino UNO 5V (użytkownik zgłosił użycie w poprzednim teście)
GPS RX  -> niepodłączony
GPS PPS -> niepodłączony
Arduino D3 (SoftwareSerial TX) -> niepodłączony do GPS
```

TX i RX są nazwane z perspektywy urządzenia, na którym znajduje się dany pin: nadajnik GPS TX wysyła do wejścia odbiorczego Arduino RX. Wspólna masa daje wspólny punkt odniesienia dla poziomów napięć.

## 4. UART w prototypie

- GPS UART: `9600 baud`.
- USB/Monitor portu szeregowego Arduino: `115200 baud`.
- `SoftwareSerial gpsSerial(4, 3)` — D4 jest RX Arduino, D3 jest TX Arduino.
- `Serial` korzysta ze sprzętowego UART ATmega328P połączonego z interfejsem USB-serial na typowym UNO R3.
- GPS używa `SoftwareSerial`, żeby nie zajmować D0/RX i D1/TX sprzętowego UART wykorzystywanego do komunikacji z komputerem.
- Domyślna konfiguracja ramki jest typowo 8N1, ale szczegółowe ustawienie parzystości/liczby bitów/bitów stopu nie zostało oddzielnie zapisane jako pomiar lub wynik testu.

## 5. Nowy odbiornik — kryteria przed zakupem i PCB

Przed ostatecznym wyborem porównać i udokumentować:

1. dokładny model odbiornika i płytki nośnej;
2. obsługiwane systemy GNSS i pasma częstotliwości;
3. dostępność aktywnej anteny, typ złącza i wymagania jej zasilania;
4. napięcie VCC oraz pobór prądu w trybie pracy i rozruchu;
5. poziomy logiczne UART TX/RX i to, czy potrzebny jest konwerter;
6. domyślne baud rate, format wyjściowy, częstotliwość aktualizacji i możliwość konfiguracji;
7. zachowanie w warunkach leśnych i przy budynkach — wymagane do późniejszego porównania testowego, bez obietnicy fixa w każdych warunkach;
8. dostęp do dokumentacji producenta i trwałą kopię datasheetu w repozytorium projektu.

Wybór konkretnego nowego odbiornika pozostaje **niezrealizowany**.
