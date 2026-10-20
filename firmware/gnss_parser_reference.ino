#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// GPS TX -> Arduino D4 (SoftwareSerial RX).
// GPS RX and PPS are not used in this receive-only prototype.
SoftwareSerial gpsSerial(4, 3);
TinyGPSPlus gps;

const unsigned long REPORT_INTERVAL_MS = 1000UL;
const unsigned long MAX_POSITION_AGE_MS = 3000UL;
const double FILTER_ALPHA = 0.25;

double filteredLat = 0.0;
double filteredLon = 0.0;
bool filterInitialized = false;
unsigned long lastReportMs = 0;

void setup() {
    Serial.begin(115200);
    gpsSerial.begin(9600);
}

void loop() {
    // Read all currently available bytes so the SoftwareSerial buffer
    // is serviced frequently while the receiver continues transmitting.
    while (gpsSerial.available() > 0) {
        char incomingByte = gpsSerial.read();
        gps.encode(incomingByte);

        // Update the filter only when TinyGPSPlus commits a new valid position.
        if (gps.location.isUpdated() && gps.location.isValid()) {
            const double rawLat = gps.location.lat();
            const double rawLon = gps.location.lng();

            if (!filterInitialized) {
                filteredLat = rawLat;
                filteredLon = rawLon;
                filterInitialized = true;
            } else {
                filteredLat += FILTER_ALPHA * (rawLat - filteredLat);
                filteredLon += FILTER_ALPHA * (rawLon - filteredLon);
            }
        }
    }

    // Use subtraction for wrap-safe elapsed-time checking with millis().
    const unsigned long now = millis();
    if (now - lastReportMs >= REPORT_INTERVAL_MS) {
        lastReportMs = now;

        const bool hasFreshFix = gps.location.isValid() &&
                                 gps.location.age() < MAX_POSITION_AGE_MS;

        if (hasFreshFix && filterInitialized) {
            Serial.print(F("FIX=YES | LAT="));
            Serial.print(filteredLat, 6);
            Serial.print(F(" | LON="));
            Serial.println(filteredLon, 6);
        } else {
            Serial.println(F("FIX=NO | LAT=-- | LON=--"));

            // Reinitialize from the next valid position after an outage.
            if (!hasFreshFix) {
                filterInitialized = false;
            }
        }
    }
}
