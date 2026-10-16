# Decyzje sprzętowe

## H-001 — Arduino UNO do testów, niezatwierdzone jako platforma końcowa

**Status:** tymczasowe.

UNO jest dostępne i nadaje się do nauki komunikacji z GNSS oraz prostych testów. ATmega328P ma ograniczone zasoby pamięci (32 KB Flash i 2 KB SRAM), więc nie zakładamy, że wystarczy do docelowego renderowania map offline. Wybór platformy końcowej nastąpi po ustaleniu wymagań mapy, ekranu, pamięci i poboru energii.

## H-002 — NEO-7M jako moduł prototypowy

**Status:** tymczasowe.

Moduł oznaczony NEO-7M-0-000 compatible przesyłał komunikaty NMEA, a podczas testu na otwartej przestrzeni uzyskał fix 3D. Nie ustalono jeszcze pełnych parametrów płytki pośredniczącej ani jej tolerancji wejścia RX. Nie należy traktować samego oznaczenia układu GNSS jako dowodu, że gotowa płytka może bezpiecznie przyjmować każde napięcie.

## H-003 — dobra dostępność pozycji w trudnych warunkach

**Status:** wymaganie projektowe, do walidacji.

Docelowo należy dążyć do możliwie dobrego odbioru w gęstym lesie i w pobliżu budynków. Rozważyć i porównać wielosystemowy odbiornik GNSS, właściwą antenę, jej położenie oraz parametry toru RF. GNSS może jednak nie ustalić pozycji w budynku lub przy całkowitym zasłonięciu nieba. Urządzenie musi wtedy poprawnie oznaczać brak aktualnego fixa, a nie przedstawiać starej pozycji jako bieżącej.

Ewentualny kompas/IMU może wspierać orientację lub krótkotrwałe szacowanie ruchu, ale nie jest bezbłędnym zamiennikiem GNSS. Taki tryb wymaga osobnej walidacji i jawnego oznaczenia niepewności.

## H-004 — kod będzie pisany etapami wspólnie z użytkownikiem

**Status:** aktywne założenie procesu.

Plik `firmware/gnss_parser/gnss_parser.ino` pozostawiono pusty celowo. Użytkownik chce samodzielnie napisać firmware, krok po kroku z pomocą asystenta, zamiast otrzymać gotowy program.

## Zasady zatwierdzania decyzji

Decyzję oznaczamy jako zatwierdzoną dopiero wtedy, gdy ma podstawę w dokumentacji, obliczeniu, pomiarze lub teście. W przeciwnym razie powinna pozostać jawnie oznaczona jako tymczasowa.
