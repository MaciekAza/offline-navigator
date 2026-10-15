# Offline GPS Navigator

A personal embedded-systems project to design and build a portable navigation device that works without an internet connection. The planned device will use GNSS positioning and locally stored OpenStreetMap-derived data, with physical controls, track and waypoint recording, and battery power.

> **Project status:** Early planning and hardware inventory. An integrated prototype, offline map rendering, and power/runtime measurements have not yet been demonstrated.

## Project goals

- Read position and time from a GNSS receiver.
- Display the current position against locally stored map data.
- Save waypoints and recorded tracks to removable storage.
- Provide a readable screen and physical controls.
- Operate from a battery with a documented power budget.
- Design a custom PCB in KiCad after validating the prototype circuits.
- Document verification, limitations, and design decisions.

## Current approach

The existing Arduino UNO R3 is a prototyping and learning platform, not yet the selected final controller. Its ATmega328P has 32 KB Flash and 2 KB SRAM, so the final controller and map-rendering approach must be selected after defining the screen, map format, and storage requirements. See [hardware decisions](docs/hardware-decisions.md).

The available GPS board is described as NEO-7M-compatible, but its exact breakout-board model, pinout, supply input, and logic levels still need verification. It must not be wired based on the chipset name alone.

## Repository structure

- `docs/architecture.md` — current high-level design and open architecture decisions.
- `docs/hardware-inventory.md` — available parts, confidence levels, and identification notes.
- `docs/hardware-decisions.md` — decisions, rationale, and items still under evaluation.
- `docs/test-results.md` — actual test procedures and observed results; no unperformed tests are reported as completed.
- `docs/troubleshooting.md` — reproducible faults, diagnosis, and fixes.
- `firmware/` — embedded software, added when the firmware work begins.
- `hardware/schematics/` — validated schematics.
- `hardware/pcb/` — KiCad board files and manufacturing outputs.
- `hardware/datasheets/` — relevant component documentation.
- `tools/map-preparation/` — tools for preparing local map data.

## Verification policy

Design calculations, expected values, and measured values are recorded separately. Test results are added only after the corresponding test has actually been performed. Unidentified parts and unverified pinouts are marked as such.

## Current milestone

**Milestone 0 — inventory and architecture:** hardware inventory supplied; final controller, display for map rendering, removable-storage hardware, power system, and exact GPS breakout remain to be selected or verified.

## Further documentation

- [Architecture](docs/architecture.md)
- [Hardware inventory](docs/hardware-inventory.md)
- [Hardware decisions](docs/hardware-decisions.md)
- [Test results](docs/test-results.md)
- [Troubleshooting](docs/troubleshooting.md)
