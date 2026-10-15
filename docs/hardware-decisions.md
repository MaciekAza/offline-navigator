# Hardware Decisions and Rationale

**Status:** Preliminary decision record. Items marked *open* are not final design choices.

## D-001 — Use the Arduino UNO R3 for early bench exercises only

**Status:** Accepted for prototyping; not selected as the final controller.

**Rationale:** It is already available and suitable for learning GPIO, ADC, UART, I²C, SPI, timing, and basic measurement. The ATmega328P has 32 KB Flash and 2 KB SRAM, so final suitability for offline-map rendering is not assumed. The map representation, display and storage approach need to be established before selecting the final controller.

**Reference:** [Official Arduino UNO R3 documentation](https://docs.arduino.cc/hardware/uno-rev3/).

## D-002 — Do not wire the GPS board until the breakout board is identified

**Status:** Safety constraint accepted; identification open.

**Rationale:** The inventory describes the board as NEO-7M-0-000 compatible, but does not establish the breakout's connector labels, supply input range, logic voltage, regulator, or level shifting. The electrical specifications of the GNSS module itself cannot automatically be applied to an unknown breakout board.

**Reference:** [u-blox NEO-7 series documentation](https://www.u-blox.com/en/product/neo-7-series) and [NEO-7 datasheet](https://content.u-blox.com/sites/default/files/products/documents/NEO-7_DataSheet_%28UBX-13003830%29.pdf).

## D-003 — Treat the available 16×2 LCDs as prototype/status displays, not as the final map display

**Status:** Provisional.

**Rationale:** Character LCDs are useful for displaying text, GPS status, coordinates, and debugging information. They are not a suitable substitute for a graphical display when the requirement is to show a map.

## D-004 — Do not select the battery or power-conversion circuit yet

**Status:** Open.

**Rationale:** The final controller, map display, storage device, GPS breakout, and target runtime have not been chosen or measured. Selecting the battery or regulators before estimating and measuring the load would be premature.

## D-005 — Keep optional modules out of the first working version unless they support a core requirement

**Status:** Provisional.

**Rationale:** The HM-10 BLE module, PN532-compatible NFC board, servos, and motor-control hardware are available, but they do not appear necessary for core offline navigation. Keeping them out of the first prototype reduces wiring and power-budget complexity.

## Open decisions

- Final controller.
- Graphical display and interface.
- GPS breakout board and electrical levels.
- Removable-storage hardware and map file format.
- Battery, charger/protection, regulators, and low-battery handling.
- Optional compass and heading strategy.
- PCB connector choices, test points and debug access.
