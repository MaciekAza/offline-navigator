# System Architecture

**Status:** Preliminary. This is a target architecture, not a claim that the system has been implemented or tested.

## Functional requirements

1. Obtain GNSS position and time.
2. Read a locally stored map without internet access.
3. Render the user's position and map on a screen.
4. Record waypoints and track points to removable storage.
5. Accept input from physical buttons.
6. Operate from a battery with a documented runtime estimate and measured validation.
7. Provide test points and accessible interfaces for debugging.

## Conceptual block diagram

```text
                 +------------------+
                 | GNSS receiver    |
                 | exact board TBD  |
                 +--------+---------+
                          | UART / interface TBD
                          v
+-----------+    +-------------------------+    +----------------+
| Buttons   +--->| Main controller         +--->| Map-capable     |
+-----------+    | final platform TBD      |    | display TBD    |
                 +------------+------------+    +----------------+
                              |
                 +------------+------------+
                 |                         |
                 v                         v
        +----------------+        +------------------+
        | Removable      |        | Optional compass |
        | storage TBD    |        | interface TBD   |
        +----------------+        +------------------+

 Battery -> protection / charging / regulation (design TBD) -> system rails
```

The diagram shows intended functions only. Interfaces, voltage rails, connectors, and the final controller are not yet frozen.

## Available prototype hardware

- Arduino UNO R3 with ATmega328P-PU for basic firmware and interface experiments.
- Two character-display options are listed in the inventory; neither is currently selected as the map display.
- A GPS board described as NEO-7M-compatible; exact board and electrical interface are not verified.
- A PN532-compatible NFC module and an HM-10 BLE module are available but are not required for the core first version.

## Important constraints

- The ATmega328P on the UNO R3 has 32 KB Flash and 2 KB SRAM. It is useful for learning and small interface tests, but it is not the assumed final platform for rendering a useful offline map. The final controller must be selected against map-format, RAM, storage, display, and power requirements.
- The current inventory does not yet confirm a microSD reader/module and card.
- A battery, charging/protection circuit, voltage regulators, and final power architecture have not yet been selected.
- The exact GPS breakout-board pinout, input-voltage range, logic levels, antenna arrangement, and output interface must be verified before wiring.
- A character LCD can be used for status/debug messages, but a map-capable screen and its interface must be chosen separately.

## Open architecture decisions

- Final controller and development environment.
- Display technology, resolution, interface, and physical size.
- Map representation and preprocessing pipeline for locally stored OpenStreetMap data.
- Removable-storage module and file format for maps, tracks, and waypoints.
- GNSS electrical interface and message protocol.
- Battery chemistry/capacity, charging, protection, regulation, and target runtime.
- Whether a compass is required and how heading will be obtained.
- Enclosure, connectors, environmental protection, and serviceability.

## Exit criteria for architecture freeze

The architecture can be considered stable only after the selected controller can handle the intended map representation and display, the GPS board is electrically identified, storage requirements are known, and the power budget has been estimated and then measured on a prototype.
