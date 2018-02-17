# Parrot — Fantasy Chess Project

Fantasy Chess Project (codenamed Parrot) to projekt gry na bazie szachów o niedoprecyzowanych wciąż zasadach.

Główna implementacja w języku C++11, nawet już się kompiluje od PR #9. I są unit testy.

## Autorzy i konsultanci

- [Remigiusz Uszok (@URemigiusz)](github.com/URemigiusz/Parrot) — pomysłodawca, Project Owner, główny etc etc, kl. 1e IV LO Toruń
- [Adam Wieczarek (@AWieczarek)](github.com/AWieczarek/Parrot) — programista […], kl. 1e IV LO Toruń
- [Jakub Kuziemski (@JakubKivi)](github.com/JakubKivi/Parrot) — programista  […], kl. 1e IV LO Toruń
- [Jakub Delicat (@delipl)](github.com/delipl/Parrot) — programista C++, kl. 1e IV LO Toruń
- [Paweł Knut](https://www.facebook.com/profile.php?id=100011873343122) — programista […], kl. 1e IV LO Toruń 
- [Zuzia Kaczorek](https://www.facebook.com/zuzia.kaczorek.7) — rysowniczka, część artystyczna jeszcze do przyłączenia do części programistycznej
- […]
- [Michał Krzysztof Feiler (@ArchieT)](github.com/ArchieT/Parrot) — konsultant od Gita oraz inżynierii oprogramowania, student I roku na WMiI UMK w Toruniu, absolwent klasy uniwersyteckiej (_E_) IV LO Toruń

## Zasady

1. Plansza ma wymiary X×Y.
2. Dwóch graczy, biały zaczyna.
3. Figury:

| Nazwa    | Codename | Wartość początkowa `HP` | Wartość `dmg` |
| -------- | -------- | ----------------------- | ------------- |
| `Pionek` | `Pawn`   | 5  | 2 |
| `Kon`    | `Knight` | 3  | 5 |
| `Goniec` | `Bishop` | 7  | 3 |
| `Wieza`  | `Rook`   | 8  | 2 |
| `Hetman` | `Queen`  | 12 | 3 |
| `Krol`   | `King`   | 20 | 2 |

4. Pola mogą być puste, zajęte przez figury, lub zajęte przez przeszkody.
