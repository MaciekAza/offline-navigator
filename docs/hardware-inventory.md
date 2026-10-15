# Hardware Inventory

**Purpose:** Record what is physically available for prototyping. An inventory entry does not mean the part has been tested or selected for the final device.

Confidence meanings:
- **Confirmed** — value/model reported as certain by the owner.
- **High** — probable identification, but not independently verified from photos or documentation.
- **By description** — identification is based on the supplied description.
- **Unknown** — must be identified before it is used in a circuit.

## Boards, displays, interfaces, and actuators

| # | Component | Marking / value | Qty. | Confidence / notes |
|---:|---|---|---:|---|
| 1 | Arduino UNO | ATmega328P-PU | 1 | Confirmed; prototyping platform |
| 2 | Solderless breadboard | Breadboard | 1 | Confirmed |
| 3 | Character LCD | RG1602A / 1602A, 16×2 | 1 | Confirmed; exact interface/backpack not specified |
| 4 | BLE module | HM-10, Bluetooth 4.0/BLE | 1 | High; exact board/version unverified |
| 5 | Servo | TowerPro SG90 | 1 | Confirmed |
| 6 | Continuous-rotation servo | SpringRC SM-S4303R | 1 | By description |
| 7 | Rotary potentiometer | 10 kΩ linear | 1 | By description |
| 8 | Trimmer potentiometer | 103, approximately 10 kΩ | 1 | High |
| 9 | Trimmer potentiometer | 102, approximately 1 kΩ | 1 | High |
| 10 | Motor-control IC/shield | L293D; MH Electronics motor-control shield also listed | 1 each / verify | L293D identification high; shield marking confirmed, exact circuit not documented |
| 11 | Grove character LCD | Grove LCD RGB Backlight V4.0, JHD1313M3, P150709 | 1 | Confirmed; interface and exact board revision to verify from its documentation |
| 12 | GNSS/GPS board | NEO-7M-0-000 compatible | 1 | High; exact breakout board, pinout, supply input and logic levels unverified |
| 13 | NFC/RFID board | NFC Module V3, probably PN532 | 1 | High; exact model and switch settings to verify |
| 14 | Tactile switches | THT tact switches | Several | Confirmed |
| 15 | Motor-control shield | MH Electronics; markings include 5V/GND/9V | 1 | Confirmed; do not infer the complete power topology from these labels alone |

## Discrete components

| # | Component | Marking / value | Qty. | Confidence / notes |
|---:|---|---|---:|---|
| 16 | Electrolytic capacitor | 1000 µF / 16 V | 1 | Confirmed |
| 17 | Electrolytic capacitor | 100 µF / 25 V | 3 | Confirmed |
| 18 | Electrolytic capacitor | 10 µF / 63 V | 1 | Confirmed |
| 19 | Capacitor | `1K63` | 2 | Marking reported; type and value not identified |
| 20 | Capacitor | `102J63` | 2 | Interpreted as 1 nF, 63 V, J tolerance; verify component marking/type before relying on it |
| 21 | Capacitor | `104K63` | 1 | Interpreted as 100 nF, 63 V, K tolerance; verify component marking/type before relying on it |
| 22 | NPN transistor | BC547B | 1 | Confirmed; pinout must be checked against the manufacturer/datasheet and package orientation |
| 23 | PNP transistor | BC558B | 1 | Confirmed; pinout must be checked against the manufacturer/datasheet and package orientation |
| 24 | Operational amplifier | LM358N | 3 | By description |
| 25 | Operational amplifier | TL082CP | 2 | By description |
| 26 | Glass diode | Marking illegible | 1 | Unknown; do not use in a circuit until identified |
| 27 | Axial resistor | Colour bands not recorded | 7 separate pieces | Unknown values; measure and/or decode before use |
| 28 | Blue-bodied resistor | Colour bands not recorded | 1 | Unknown value; measure and/or decode before use |
| 29 | LEDs | Red, green, blue, yellow, etc. | Many | Confirmed; individual electrical ratings not inventoried |

## Tools reported separately

- Digital multimeter — available; exact make/model not recorded.
- USB cable for Arduino UNO R3 — available.
- Jumper wires — available.
- Computer with Arduino IDE — available.
- Soldering iron and solder — available.
- Utility knife — available; no wire stripper/cutters confirmed.
- Bench power supply — not available at present; acquire/rent only if a later test requires it.

## Missing or unconfirmed items for the final navigator

- microSD card reader/module and a suitable card.
- Battery and its protection/charging solution.
- Voltage regulators and any required level shifting, selected from verified requirements.
- Map-capable graphical display.
- Exact GPS breakout documentation and antenna details.
- Final host controller.
- Final enclosure and connectors.

This list means these items were not identified in the submitted inventory; it does not prove they are not owned.

## Safety notes

- Do not connect the GPS board until the exact breakout, supply input and logic levels are identified. The bare u-blox NEO-7M module's documented supply range is not a guarantee of the input range of a third-party breakout board.
- Do not use the unidentified diode or `1K63` capacitors in an important circuit until identified.
- Confirm electrolytic capacitor polarity before powering a circuit.
- Confirm transistor pinout for the exact manufacturer/package before wiring.
