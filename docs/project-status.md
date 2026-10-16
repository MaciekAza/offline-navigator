# Status projektu i najbliższe kroki

## Obecny stan

- **Prototyp:** Arduino UNO R3 + odbiornik na płytce oznaczonej `NEO-7M-0-000 compatible`.
- **Komunikacja:** odbiór NMEA przez UART/SoftwareSerial działał w testach użytkownika.
- **Pozycja:** uzyskano autonomiczny fix 3D na otwartej przestrzeni.
- **Firmware:** szkic TinyGPSPlus raportuje `FIX=YES/NO` oraz jedną parę filtrowanych współrzędnych. Skrócona rewizja powinna być zweryfikowana ponownie po wgraniu z bieżącego repozytorium.
- **Dokładność:** nie ustalono błędu bezwzględnego; próbkowane współrzędne zmieniały się w czasie. HDOP jest wskaźnikiem geometrii, a nie błędem wyrażonym w metrach.
- **Sprzęt finalny:** kontroler, ekran mapowy, microSD, zasilanie, antena i PCB pozostają do wyboru.

## Co zrobić dalej

1. Otworzyć `firmware/gnss_parser/gnss_parser.ino` w Arduino IDE.
2. Skompilować i wgrać na Arduino UNO z zainstalowaną biblioteką TinyGPSPlus.
3. Sprawdzić, czy raport jest dokładnie w formacie `FIX=YES | LAT=... | LON=...` i czy po utracie aktualnej pozycji pojawia się `FIX=NO | LAT=-- | LON=--`.
4. Następnie rozwijać firmware w małych, testowalnych częściach — najpierw walidacja jakości pozycji, potem test zapisu punktu/śladu, a dopiero później UI/ekran i mapy.
5. Przed decyzją o finalnej PCB określić wymagania funkcjonalne i porównać platformy pod względem RAM, Flash, interfejsów, wydajności, poboru prądu i kosztu.

## Wymaganie użytkowe

Nawigacja powinna możliwie dobrze pracować w gęstym lesie i przy budynkach. To cel optymalizacji i testów, nie gwarancja fixa GNSS wewnątrz budynku. W trybie utraty fixa urządzenie nie może udawać, że nieaktualna współrzędna jest aktualną pozycją.
