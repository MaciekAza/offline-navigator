# Inwentaryzacja sprzętu

**Status:** spis przekazany przez autora projektu; część oznaczeń wymaga fizycznego potwierdzenia. „Pewne” oznacza pewność spisu użytkownika, a nie niezależną weryfikację parametrów elektrycznych.

## Płytki, moduły i elementy elektromechaniczne

| Element | Oznaczenie / wartość | Ilość | Pewność / uwagi |
|---|---|---:|---|
| Arduino UNO | ATmega328P-PU | 1 | Pewne |
| Płytka stykowa | Breadboard | 1 | Pewne |
| Wyświetlacz LCD | RG1602A / 1602A, 16×2 | 1 | Pewne; wariant interfejsu do ustalenia |
| Moduł Bluetooth | HM-10, Bluetooth 4.0/BLE | 1 | Bardzo duża; dokładna wersja płytki do weryfikacji |
| Serwomechanizm | TowerPro SG90 | 1 | Pewne |
| Serwomechanizm | SpringRC SM-S4303R | 1 | Z opisu |
| Potencjometr obrotowy | 10 kΩ liniowy | 1 | Z opisu |
| Potencjometr montażowy | 103, około 10 kΩ | 1 | Bardzo duża |
| Potencjometr montażowy | 102, około 1 kΩ | 1 | Bardzo duża |
| Driver silników | L293D | 1 | Bardzo duża; obudowa/moduł do weryfikacji |
| Motor Control Shield | MH Electronics; opisy 5V/GND/9V | 1 | Pewne; dokładny model i schemat niepotwierdzone |
| Moduł NFC/RFID | NFC Module V3, prawdopodobnie PN532 I2C | 1 | Bardzo duża; pinout i wybór interfejsu do weryfikacji |
| Przyciski | Tact Switch THT | Kilka | Pewne |
| Moduł GPS | Opisywany jako NEO-7M-0-000 compatible | 1 | Bardzo duża co do rodziny; dokładny breakout, pinout i regulator niepotwierdzone |
| Wyświetlacz Grove | Grove LCD RGB Backlight V4.0; JHD1313M3; P150709 | 1 | Pewne; interfejs do potwierdzenia na podstawie wersji płytki |

## Elementy dyskretne i analogowe

| Element | Oznaczenie / wartość | Ilość | Pewność / uwagi |
|---|---|---:|---|
| Kondensator elektrolityczny | 1000 µF / 16 V | 1 | Pewne |
| Kondensator elektrolityczny | 100 µF / 25 V | 3 | Pewne |
| Kondensator elektrolityczny | 10 µF / 63 V | 1 | Pewne |
| Kondensator | 1K63 | 2 | Oznaczenie pewne; typ i pojemność do potwierdzenia |
| Kondensator | 102J63, prawdopodobnie 1 nF / 63 V | 2 | Wartość prawdopodobna; do potwierdzenia kodu i typu |
| Kondensator | 104K63, prawdopodobnie 100 nF / 63 V | 1 | Wartość prawdopodobna; do potwierdzenia kodu i typu |
| Tranzystor NPN | BC547B | 1 | Pewne; pinout konkretnego producenta do sprawdzenia w nocie katalogowej |
| Tranzystor PNP | BC558B | 1 | Pewne; pinout konkretnego producenta do sprawdzenia w nocie katalogowej |
| Wzmacniacz operacyjny | LM358N | 3 | Z opisu |
| Wzmacniacz operacyjny | TL082CP | 2 | Z opisu |
| Dioda | Szklana, oznaczenie niewidoczne | 1 | Model i polaryzacja do ustalenia |
| Rezystory | Paski kolorowe | 7 | Wartości nieustalone |
| Rezystor | Niebieska obudowa, paski | 1 | Wartość nieustalona |
| LED | Czerwone, zielone, niebieskie, żółte itd. | Dużo | Typy i parametry nieustalone |

## Narzędzia — według deklaracji użytkownika

| Narzędzie | Status | Uwagi |
|---|---|---|
| Multimetr cyfrowy | Jest | Model i funkcje zakresów nieznane |
| Arduino IDE na komputerze | Jest | Potwierdzić płytkę/port podczas pierwszego testu firmware |
| Kabel USB do UNO R3 | Jest | Typ przewodu i stan niezweryfikowane |
| Przewody połączeniowe | Są | Rodzaj i ilość nieustalone |
| Dodatkowe rezystory | Są | Wartości nieustalone |
| Lutownica i cyna | Są | Nie są potrzebne do pierwszego etapu |
| Zasilacz laboratoryjny | Brak | Możliwy zakup/organizacja, gdy pojawi się uzasadniona potrzeba |
| Obcinaczki/ściągacz izolacji | Brak; dostępny nóż | Preferować gotowe przewody; ostrożnie z ostrzem |
| Osobna płytka stykowa | Jest według aktualnej listy | Arduino UNO nie zastępuje breadboardu |

## Braki istotne dla nawigacji

- Niepotwierdzony czytnik microSD.
- Niepotwierdzony ekran nadający się do czytelnego wyświetlania mapy.
- Brak ustalonego akumulatora, układu ładowania, regulatorów i zabezpieczeń.
- Brak potwierdzonego modułu kompasu.
- Brak weryfikacji pinoutu i interfejsów płytki GPS.

## Zasady aktualizacji

Nie zmieniać statusu elementu na „zweryfikowany” tylko na podstawie nazwy z oferty lub podobieństwa wizualnego. Zapisać oznaczenie układu, oznaczenia płytki, źródło dokumentacji i ewentualne zmierzone parametry. Do README trafiają tylko istotne, potwierdzone zmiany.
