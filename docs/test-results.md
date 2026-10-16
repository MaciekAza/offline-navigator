# Wyniki testów

Dokument zawiera testy, które potwierdzają działanie bloków urządzenia. Nie zapisujemy tu każdej czynności z nauki. Dokładne współrzędne z próbek GNSS zostały pominięte ze względu na prywatność.

## Podsumowanie

| ID | Test | Status | Potwierdzenie / ograniczenie |
|---|---|---|---|
| T-001 | Identyfikacja modułu GNSS | Częściowa | Podane oznaczenie `NEO-7M-0-000 compatible` oraz piny PPS/RX/TX/GND/VCC; dokładny wariant płytki i elektryczne parametry wejść nadal niepotwierdzone. |
| T-002 | Odbiór surowych danych NMEA przez Arduino UNO | Zaliczone | W monitorze szeregowym widoczne powtarzające się zdania GGA/GSA/GSV/GLL/RMC/VTG. |
| T-003 | Uzyskanie fixa na otwartej przestrzeni | Zaliczone dla podstawowej funkcji | Próbki zawierały `GGA quality=1`, `GSA fix type=3` i `RMC/GLL status=A`. |
| T-004 | Utrzymanie fixa po ok. 3 min na zewnątrz | Wstępnie zaliczone | W jednej próbce: 6 satelitów użytych, 9 raportowanych przez GSV, HDOP 1,98, PDOP 2,51, VDOP 1,54. To wskaźniki geometrii, nie bezpośredni pomiar błędu w metrach. |
| T-005 | Dalsza próbka pozycji i kontrola sum kontrolnych | Wstępnie zaliczone | Późniejsze raporty: 5–6 satelitów, HDOP ok. 1,49–1,50, `checksum_errors=0`. |
| T-006 | Prosty filtr współrzędnych | Wynik działania potwierdzony, dokładność nieoceniona | W raporcie widoczne były wartości `RAW` i `FILT`; filtr zmniejszał ruch wskazania, ale pozycja nadal się zmieniała. Nie wykonano porównania z certyfikowanym punktem odniesienia. |
| T-007 | Skrócony raport `FIX=YES/NO` + jedna para współrzędnych | Do ponownego potwierdzenia po aktualizacji | Obecna wersja `firmware/gnss_parser/gnss_parser.ino` zawiera uproszczony format; po wgraniu tej wersji ponownie sprawdzić wyjście. |
| T-008 | Zapis/odczyt microSD | Nie rozpoczęto | Czytnik microSD nie został jeszcze potwierdzony. |
| T-009 | Ekran mapowy/UI | Nie rozpoczęto | Dostępne ekrany 16×2 nie zostały wybrane jako docelowy ekran mapy. |
| T-010 | Budżet energetyczny | Nie rozpoczęto | Brak kompletnej konfiguracji i pomiaru poboru całego urządzenia. |
| T-011 | Schemat i PCB | Nie rozpoczęto | Nie przygotowano finalnego schematu/PCB. |

## T-002/T-003 — odbiór NMEA i fix na zewnątrz

- **Połączenie danych użyte w teście:** GPS TX → Arduino D4 przez `SoftwareSerial`; GND wspólne; GPS RX i PPS nieużywane.
- **Prędkość GPS:** 9600 baud; Monitor portu szeregowego: 115200 baud.
- **Wynik wewnątrz budynku:** log pokazywał `GGA quality=0`, `GSA fix mode=1`, `00` satelitów użytych do pozycji oraz `RMC status=V`. To potwierdza brak fixa w tej próbie, nie awarię modułu.
- **Wynik na otwartej przestrzeni:** pojawiły się komunikaty z autonomicznym fixem 3D (`GGA quality=1`, `GSA fix type=3`, `RMC/GLL status=A`).
- **Jakość pierwszej zewnętrznej próbki:** 4 satelity użyte, HDOP ok. 10,42. Późniejsza próbka po około 3 minutach: 6 satelitów użytych, HDOP 1,98.
- **Późniejsze próbki:** raportowano 5–6 satelitów, HDOP ok. 1,49–1,50 oraz zero błędów sum kontrolnych.
- **Rozrzut pozycji:** próbki przekazane podczas testu z nieruchomym odbiornikiem zmieniały się w przybliżonym zakresie kilku metrów. To zakres między pokazanymi pomiarami, nie błąd względem prawdziwej pozycji; nie zastosowano niezależnego punktu odniesienia.
- **Werdykt:** komunikacja UART oraz uzyskanie fixa na zewnątrz są potwierdzone. Rzeczywista dokładność w metrach i zachowanie w lesie/budynkach pozostają nieweryfikowane.

## FW-001 — parser GNSS i filtr

- **Cel:** przeanalizować strumień NMEA i uzyskać współrzędne użyteczne dla nawigacji.
- **Implementacja:** `firmware/gnss_parser/gnss_parser.ino`, biblioteki SoftwareSerial i TinyGPSPlus.
- **Działanie potwierdzone:** użytkownik przekazał raporty z `FIX=YES`, `RAW_lat/RAW_lon`, `FILT_lat/FILT_lon`, liczbą satelitów, HDOP i zerem błędów sum kontrolnych.
- **Aktualna rewizja:** raport skrócono zgodnie z wymaganiem do `FIX=YES/NO | LAT | LON`, współrzędne poddane prostemu filtrowaniu. Po przeniesieniu tej rewizji z repozytorium należy potwierdzić Verify/Upload i oba stany fixa.
- **Ograniczenia:** `FIX=YES` oznacza poprawną pozycję nie starszą niż 3 s, a nie określoną dokładność. Filtr może zmniejszyć krótkookresowe wahania, ale wprowadza opóźnienie przy ruchu.

## Kryteria przyszłego testu GNSS

Dla porównywalnych testów na otwartej przestrzeni, przy zabudowie i pod gęstymi drzewami rejestrować: czas do fixa, status/typ fixa, satelity użyte, HDOP, utratę i odzyskanie fixa, a jeśli dostępne — pobór mocy. Do oceny błędu bezwzględnego potrzebny jest wiarygodny punkt odniesienia. Nie publikować dokładnych współrzędnych prywatnych lokalizacji.

## Format zapisu istotnego testu

- **ID / cel:**
- **Konfiguracja:**
- **Procedura:**
- **Oczekiwany wynik:**
- **Wynik rzeczywisty:**
- **Kryterium zaliczenia:**
- **Werdykt:** zaliczony / niezaliczony / nierozstrzygnięty
- **Dowody i ograniczenia:**
