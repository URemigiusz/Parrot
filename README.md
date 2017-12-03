# Parrot — Fantasy Chess Project

Fantasy Chess Project (codenamed Parrot) to projekt gry na bazie szachów o niedoprecyzowanych wciąż zasadach.

Główna implementacja w języku C++11, nawet już się kompiluje od PR #9. I są unit testy.

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
