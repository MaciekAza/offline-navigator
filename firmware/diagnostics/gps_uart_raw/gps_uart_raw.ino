/*
  offline-navigator — GPS UART raw diagnostic

  Purpose:
    Forward NMEA sentences from a GPS receiver to the USB Serial Monitor.

  Wiring used for this test:
    GPS TX  -> Arduino D4 (SoftwareSerial RX)
    GPS GND -> Arduino GND
    GPS RX  -> not connected
    GPS PPS -> not connected

  IMPORTANT:
    Before connecting VCC, verify the exact breakout board's power input
    requirements. The voltage limits of the u-blox receiver IC alone do not
    establish the allowed input voltage of the complete breakout board.

  Serial settings:
    GPS UART: 9600 baud (assumed default for this test; confirm if output differs)
    USB Serial Monitor: 115200 baud
*/

#include <SoftwareSerial.h>

constexpr uint8_t GPS_RX_PIN = 4; // Arduino receives from GPS TX
constexpr uint8_t GPS_TX_PIN = 3; // Not wired to GPS RX in this receive-only test
constexpr unsigned long GPS_BAUD = 9600;
constexpr unsigned long USB_BAUD = 115200;

SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);

void setup() {
  Serial.begin(USB_BAUD);
  gpsSerial.begin(GPS_BAUD);
  Serial.println(F("GPS UART raw diagnostic started"));
  Serial.println(F("Forwarding bytes from GPS UART; no position validity is assumed."));
}

void loop() {
  while (gpsSerial.available() > 0) {
    Serial.write(gpsSerial.read());
  }
}
