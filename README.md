# Offline Navigator

Projekt przenośnej nawigacji GNSS działającej bez internetu. Docelowo urządzenie ma wyświetlać lokalne mapy OpenStreetMap, pokazywać bieżącą pozycję, zapisywać punkty i ślady, obsługiwać ekran i przyciski oraz pracować z akumulatora. Projekt obejmuje również własny schemat i PCB w KiCad.

> **Status:** wczesny prototyp. Potwierdzono odbiór NMEA przez Arduino UNO R3 i uzyskanie autonomicznego fixa 3D na otwartej przestrzeni. Powstał szkic firmware używający TinyGPSPlus oraz prostego filtra współrzędnych. Nawigacja po mapie, zapis śladów, docelowe zasilanie i PCB nie są jeszcze zaimplementowane.

## Główne osiągnięcia

- [x] Uruchomiono odbiór NMEA z obecnego modułu GNSS przez UART/SoftwareSerial.
- [x] Odebrano poprawne komunikaty NMEA i potwierdzono autonomiczny fix 3D na zewnątrz.
- [x] Odczytano dane GPS przez bibliotekę TinyGPSPlus.
- [x] Dodano prosty filtr wygładzający pozycję i raport `FIX=YES/NO` wraz ze współrzędnymi.
- [ ] Ponownie zweryfikować skróconą wersję raportowania po wgraniu jej z repozytorium.
- [ ] Zmierzyć rozrzut pozycji w dłuższym teście na otwartej przestrzeni i porównać go z punktem odniesienia.
- [ ] Zdefiniować wymagania dla docelowego ekranu, kontrolera, formatu map i pamięci.
- [ ] Dodać odczyt lokalnych map, interfejs użytkownika oraz zapis punktów i śladów.
- [ ] Opracować budżet energetyczny i układ zasilania akumulatorowego.
- [ ] Zaprojektować schemat i PCB w KiCad, następnie wykonać testy prototypu.

## Aktualna platforma testowa

- Arduino UNO R3 z ATmega328P-PU.
- Odbiornik na płytce oznaczonej jako `NEO-7M-0-000 compatible`.
- W testowanej konfiguracji: GPS TX → Arduino D4, wspólna masa, GPS UART 9600 baud, Monitor portu szeregowego 115200 baud.
- GPS RX i PPS pozostają niepodłączone w teście odbioru.
- Biblioteka firmware: TinyGPSPlus; SoftwareSerial jest używany do odbioru GPS.

UNO jest platformą prototypową, a nie zatwierdzonym kontrolerem finalnym. ATmega328P ma ograniczoną pamięć, więc wybór docelowej platformy wymaga określenia formatu map, rozdzielczości ekranu, RAM/Flash i budżetu energii.

## Założenie dotyczące odbioru w trudnych warunkach

Wymaganiem projektu jest możliwie dobra dostępność pozycji w gęstym lesie i w pobliżu budynków. Nie zakładamy, że GNSS zawsze uzyska fix wewnątrz budynku. Docelowo ocenimy nowocześniejszy odbiornik wielokonstelacyjny, antenę i jej umiejscowienie oraz zachowanie interfejsu po utracie fixa. Kompas/IMU mogą być rozważone jako pomocnicze źródła danych, z jawnym oznaczeniem narastającej niepewności.

## Struktura repozytorium

- `firmware/gnss_parser/` — parser GNSS i zwięzły raport pozycji.
- `firmware/diagnostics/gps_uart_raw/` — minimalny szkic diagnostyczny do przepuszczania surowych komunikatów NMEA.
- `hardware/schematics/` — schematy elektroniczne.
- `hardware/pcb/` — projekt PCB.
- `hardware/datasheets/` — dokumentacja elementów.
- `docs/architecture.md` — plan bloków urządzenia.
- `docs/hardware-inventory.md` — dostępne komponenty i niepewności.
- `docs/hardware-decisions.md` — istotne decyzje sprzętowe.
- `docs/test-results.md` — wyniki testów bloków urządzenia.
- `docs/troubleshooting.md` — problemy wpływające na projekt i ich rozwiązania.
- `tools/map-preparation/` — przyszłe narzędzia do przygotowania map offline.

## Firmware — uruchomienie

1. Otwórz `firmware/gnss_parser/gnss_parser.ino` w Arduino IDE.
2. Zainstaluj bibliotekę **TinyGPSPlus by Mikal Hart** przez Library Manager.
3. Wybierz Arduino Uno i właściwy port COM.
4. Skompiluj (Verify), wgraj (Upload) i otwórz Serial Monitor na `115200 baud`.
5. Zachowaj obecną, sprawdzoną konfigurację zasilania modułu GPS; dokładny wariant płytki pośredniczącej i jej parametry elektryczne nadal wymagają niezależnej weryfikacji.

Raport pokazuje tylko `FIX`, `LAT` i `LON`. `FIX=YES` znaczy, że parser ma poprawną pozycję nie starszą niż trzy sekundy; **nie jest gwarancją określonej dokładności w metrach**. Współrzędne są prywatnymi danymi lokalizacyjnymi — nie publikuj w repozytorium surowych logów z dokładną lokalizacją domu lub innych wrażliwych miejsc.

## Zasada portfolio

Repozytorium nie jest dziennikiem każdej lekcji. Dokumentujemy funkcjonalne kamienie milowe, istotne decyzje, schematy, firmware i testy, które potwierdzają działanie urządzenia. Wyniki wpisujemy jako rzeczywiste tylko wtedy, gdy wynikają z faktycznego testu.
