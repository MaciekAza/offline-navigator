# GNSS parser i zwięzły raport pozycji

## Cel

Odbierać NMEA z aktualnego modułu GNSS, parsować dane TinyGPSPlus i raportować wyłącznie status fixa oraz pojedynczą parę współrzędnych po prostym filtrowaniu wykładniczym. Jest to prototyp firmware, a nie ukończony system nawigacji.

## Zależności

- Arduino IDE i obsługa płytek Arduino AVR.
- `TinyGPSPlus` by Mikal Hart — instalacja przez Library Manager.
- `SoftwareSerial` — biblioteka dostępna z platformą Arduino AVR.

## Połączenia użyte w działającym teście odbioru

- GPS `TX` → Arduino UNO `D4`.
- GPS `GND` → Arduino `GND`.
- GPS `RX` i `PPS` pozostają niepodłączone w tym teście.
- Dla `VCC` zachowaj aktualną, działającą konfigurację zasilania. Dokładny model płytki pośredniczącej, tor zasilania i poziomy logiczne nie zostały w pełni zidentyfikowane; nie zmieniaj zasilania bez weryfikacji dokumentacji płytki.

Konstruktor `SoftwareSerial(4, 3)` przyjmuje kolejno pin RX Arduino i pin TX Arduino. GPS `TX` podłączamy więc do D4. Pin Arduino D3 nie jest podłączony do GPS RX w tym wariancie.

## Uruchomienie

1. Otwórz `gnss_parser.ino`.
2. W Arduino IDE wybierz **Arduino Uno** i właściwy port COM.
3. Wybierz **Verify**, następnie **Upload**.
4. Otwórz Serial Monitor na `115200 baud`.
5. Dla zwiększonej szansy uzyskania fixa testuj na otwartej przestrzeni i ustaw antenę ku niebu zgodnie z jej konstrukcją.

## Wyjście

Przy świeżej, prawidłowej pozycji:

```text
FIX=YES | LAT=... | LON=...
```

Gdy pozycja jest nieważna lub starsza niż 3 s:

```text
FIX=NO | LAT=-- | LON=--
```

`FIX=YES` nie oznacza gwarantowanej dokładności w metrach. `LAT` i `LON` są współrzędnymi filtrowanymi; filtr zmniejsza krótkookresowe skoki, ale może opóźniać pozycję podczas ruchu i nie usuwa błędów systematycznych GNSS.

## Parametry filtra

- `FILTER_ALPHA = 0.25`: udział nowego pomiaru w aktualizacji filtra. Mniejsza wartość zwykle wygładza silniej, ale zwiększa opóźnienie.
- `MAX_POSITION_AGE_MS = 3000`: maksymalny wiek lokalizacji, by pokazać `FIX=YES`.
- `REPORT_INTERVAL_MS = 1000`: odstęp pomiędzy raportami.

Zmiany tych parametrów powinny być oceniane zarówno w teście statycznym, jak i podczas marszu.
