# GPS UART raw diagnostic

Minimal receive-only test for checking whether the GPS module sends serial data.

## Wiring

- GPS `TX` → Arduino UNO `D4` (`SoftwareSerial` RX)
- GPS `GND` → Arduino `GND`
- GPS `RX` → leave unconnected for this test
- GPS `PPS` → leave unconnected for this test
- GPS `VCC` → only after confirming the breakout board's input-voltage requirements

## Run

1. Open `gps_uart_raw.ino` in Arduino IDE.
2. Select Arduino UNO and the correct serial port.
3. Upload the sketch.
4. Open Serial Monitor at **115200 baud**.
5. The sketch listens to the GPS UART at **9600 baud** and forwards bytes unchanged.

## Interpretation

NMEA sentences appearing in the Serial Monitor confirm that serial data is being received. They do **not** prove that the receiver has a valid satellite fix. For a valid position, inspect fields such as the GGA quality indicator (`1` for a standard GPS fix) and RMC/GLL status (`A` means valid). `GGA quality 0`, `GSA fix mode 1`, `RMC/GLL status V`, or position mode `N` indicate no valid fix.

If the module baud rate or wiring differs, adapt the sketch only after documenting the actual module and connection.
