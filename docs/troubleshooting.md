# Rozwiązywanie problemów

Repozytorium zawiera tylko problemy istotne dla firmware, sprzętu lub powtarzalności testów. Proste ćwiczenia edukacyjne nie wymagają osobnych wpisów.

## GPS-001 — NMEA jest odbierane, ale nie ma fixa

- **Objaw:** NMEA dociera do Arduino, lecz GGA quality wynosi `0`, GSA fix mode `1`, a RMC/GLL status to `V`.
- **Wynik testu:** w pomieszczeniu użytkownik zaobserwował brak fixa; po przeniesieniu odbiornika na zewnątrz uzyskano fix 3D.
- **Wniosek:** komunikacja UART może działać, mimo że pozycja GNSS nie jest dostępna. Brak fixa w pomieszczeniu sam w sobie nie dowodzi awarii odbiornika.
- **Diagnostyka:** otwarta przestrzeń, niezasłonięta antena, obserwacja jakości fixa i satelitów, a potem kontrola połączenia antenowego i dokumentacji płytki.

## GPS-002 — pozycja waha się przy nieruchomym odbiorniku

- **Objaw:** szerokość i długość zmieniają się pomiędzy kolejnymi raportami, mimo że odbiornik został pozostawiony nieruchomo.
- **Dane:** w przekazanym teście HDOP wynosił ok. 1,49–1,50, liczba satelitów użytych 5–6, a sumy kontrolne NMEA nie wykazywały błędów.
- **Wniosek:** poprawne sumy kontrolne potwierdzają integralność odebranych zdań, ale nie gwarantują dokładności pozycji. GNSS wykazuje szum i dryf.
- **Działanie:** zachować surowy pomiar w diagnostyce; używać filtrowania wyłącznie jako wygładzania wskazania; dokładność bezwzględną oceniać względem niezależnego punktu odniesienia.
- **Ograniczenie filtra:** silniejsze wygładzanie zwiększa opóźnienie podczas marszu. Trzeba przetestować zarówno postój, jak i ruch.

## GNSS parser — typowe problemy

- Jeśli kompilator zgłasza brak `TinyGPS++.h`, zainstalować `TinyGPSPlus` przez Library Manager.
- Jeśli nie ma znaków NMEA, sprawdzić GPS TX → Arduino D4, wspólną masę, aktualną konfigurację zasilania i prędkość UART 9600 baud.
- Monitor portu szeregowego musi być ustawiony na 115200 baud.
- `FIX=NO` może oznaczać brak świeżej pozycji, nawet jeśli strumień NMEA jest odbierany poprawnie.
- Nie podłączać Arduino TX do GPS RX, dopóki nie zostaną potwierdzone poziomy logiczne konkretnej płytki GNSS.
