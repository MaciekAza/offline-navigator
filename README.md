# Offline Navigator

**Portablena nawigacja GPS z mapami offline — projekt sprzętowo-programistyczny**

> **Status:** planowanie i weryfikacja komponentów. Nie ma jeszcze potwierdzonego, działającego prototypu.

## Cel projektu

Zaprojektować przenośne urządzenie, które działa bez dostępu do internetu i potrafi odczytać pozycję GNSS, wyświetlać mapę przechowywaną lokalnie oraz zapisywać punkty i ślady trasy. Projekt obejmuje firmware, elektronikę, własną płytkę PCB i testy kompletnego urządzenia.

## Planowane funkcje

- [ ] Odczyt pozycji z odbiornika GNSS.
- [ ] Wyświetlanie pozycji na lokalnych danych mapowych opartych na OpenStreetMap.
- [ ] Zapisywanie i odczytywanie punktów oraz śladów trasy.
- [ ] Obsługa karty microSD.
- [ ] Ekran i przyciski do obsługi urządzenia.
- [ ] Zasilanie akumulatorowe z kontrolą poboru energii.
- [ ] Schemat i PCB zaprojektowane w KiCad.
- [ ] Obudowa oraz testy końcowe.

Lista opisuje **cele**, a nie ukończone funkcje. Checkboxy będą zmieniane dopiero po weryfikacji danego elementu.

## Aktualny stan

- Zebrano wstępny spis dostępnych komponentów: [`docs/hardware-inventory.md`](docs/hardware-inventory.md).
- Architektura urządzenia jest koncepcyjna; nie wybrano jeszcze docelowego mikrokontrolera, ekranu ani toru zasilania.
- Moduł GPS jest opisywany jako zgodny z NEO-7M, ale jego konkretna płytka pośrednicząca, pinout i dopuszczalne poziomy logiczne nie zostały potwierdzone.
- Nie ma jeszcze wyników testów działającego prototypu.

## Ważne założenia techniczne

Arduino UNO R3 będzie na początku platformą do krótkich eksperymentów z elektroniką i interfejsami. Nie zakładamy, że stanie się kontrolerem końcowym nawigacji. Ma ATmega328P z 32 KB Flash i 2 KB SRAM, co mocno ogranicza możliwość pracy z mapami i buforami obrazu. Ostateczny wybór platformy nastąpi po oszacowaniu wymagań map, ekranu, pamięci i poboru energii.

Nieznanych modułów nie podłączamy, dopóki nie zweryfikujemy ich wersji, zasilania, pinoutu oraz poziomów logicznych.

## Kamienie milowe

1. **Weryfikacja komponentów i wymagań** — rozpoznanie modułów, potwierdzenie pinoutów i ograniczeń elektrycznych.
2. **Prototyp GNSS** — odczyt i walidacja komunikatów pozycji.
3. **Pamięć danych** — zapis i odczyt punktów oraz śladów na microSD.
4. **Interfejs użytkownika** — ekran, przyciski i podstawowe widoki.
5. **Obsługa map offline** — wybór formatu danych, przygotowanie map i renderowanie.
6. **Architektura zasilania** — budżet energetyczny, dobór akumulatora i regulatorów.
7. **Integracja i PCB** — schemat, layout, prototyp płytki i kontrolowane uruchomienie.
8. **Obudowa i walidacja** — testy funkcjonalne, energetyczne i terenowe.

Kamienie milowe mogą zostać podzielone lub zmienione po testach i analizie ograniczeń sprzętu.

## Struktura repozytorium

```text
offline-navigator/
├── README.md
├── docs/
│   ├── architecture.md
│   ├── hardware-inventory.md
│   ├── hardware-decisions.md
│   ├── test-results.md
│   └── troubleshooting.md
├── firmware/
├── hardware/
│   ├── schematics/
│   ├── pcb/
│   └── datasheets/
├── images/
│   └── prototype/
└── tools/
    └── map-preparation/
```

## Standard dowodów

Status funkcji lub testu oznaczamy jako ukończony tylko wtedy, gdy istnieje sprawdzalny dowód: kod, schemat, nagranie/zdjęcie działającego prototypu, powtarzalna procedura lub zapis rzeczywistego pomiaru. Obliczenia i przewidywania opisujemy oddzielnie od wyników zmierzonych.

## Technologie i narzędzia

- C/C++ i platforma mikrokontrolerowa — do ustalenia na podstawie wymagań.
- KiCad — schemat i PCB.
- OpenStreetMap — źródło danych mapowych; format i proces przygotowania danych zostaną wybrane później.
- Git i GitHub — wersjonowanie projektu oraz prezentacja końcowych artefaktów technicznych.

## Licencja

Licencja projektu nie została jeszcze wybrana. Przed publicznym udostępnieniem kodu, dokumentacji i projektu PCB należy określić, na jakich zasadach inni mogą z nich korzystać.
