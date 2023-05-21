# ***Dokumentacja***

# Kamień Papier Nożyce:
Gra w kamień, papier, nożyce jest grą towarzyską, w której dwie osoby wykonują ruchy, wybierając jeden z trzech elementów: kamień, papier lub nożyce. Poniżej przedstawiam zasady tej gry:


1.Kamień pokonuje nożyce: Jeśli jedna osoba wybierze kamień, a druga nożyce, kamień zwycięża, ponieważ kamień tępi nożyce.

2.Papier pokonuje kamień: Jeśli jedna osoba wybierze papier, a druga kamień, papier zwycięża, ponieważ można owinąć kamień wokół papieru.

3.Nożyce pokonują papier: Jeśli jedna osoba wybierze nożyce, a druga papier, nożyce zwyciężają, ponieważ nożyczki są w stanie je przeciąć.

4.Jeśli obie osoby wybiorą ten sam element, mamy remis.

# Spis funkcji
1. generateComputerMove()
2. getPlayerMove()
3. determineWinner()
4. playAgain()
5. main()


# Opis funkcji 

# 1. *generateComputerMove()*

Funkcja **generateComputerMove()** generuje losowy ruch komputera w zakresie od 1 do 3. Wykorzystuje do tego funkcję **rand()**, która zwraca liczbę pseudolosową, a operator **%** służy do obliczenia reszty z dzielenia. W tym przypadku % 3 powoduje ograniczenie wyniku do zakresu od 0 do 2, a dodanie + 1 przesuwa ten zakres do 1-3, co odpowiada kamieniowi, papierowi i nożycym. Ostatecznie funkcja zwraca wylosowany ruch komputera.

```C++
int generateComputerMove() {
    return rand() % 3 + 1; // Generowanie losowego ruchu komputera (1-3)
}
```
# 2. *getPlayerMove()*

Funkcja ta umożliwia graczowi wprowadzenie numeru od 1 do 3, odpowiadającego kamieniowi, papierowi lub nożyczkom, a następnie zwraca ten wybrany ruch do dalszego przetwarzania w programie.

```C++
int getPlayerMove() {
    int move;
    cout << "Wybierz swoj ruch (1-3): ";
    cin >> move;
    cout << endl;
    return move;
}
```
# 3. *determineWinner()*

Funkcja determineWinner() jest odpowiedzialna za określenie zwycięzcy gry w kamień, papier, nożyce na podstawie wybranych ruchów gracza i komputera.

```C++
void determineWinner(int playerMove, int computerMove) {
    cout << "Komputer wybral: " << computerMove << endl<<endl;

    if (playerMove == computerMove) {
        cout << "Remis!" << endl<<endl;;
    } else if (
        (playerMove == 1 && computerMove == 3) ||
        (playerMove == 2 && computerMove == 1) ||
        (playerMove == 3 && computerMove == 2)
    ) {
        cout << "Gracz wygrywa!" << endl<<endl;
    } else {
        cout << "Komputer wygrywa!" << endl<<endl;
    }
}
```

# 4. *playAgain()*

Funkcja **playAgain()** pozwala na interakcję z użytkownikiem, pytając go, czy chce zagrać ponownie. Zwraca **true**, jeśli użytkownik wybierze 'T' lub 't', co oznacza chęć ponownej gry. Zwraca **false**, jeśli użytkownik wybierze 'N' lub 'n', co oznacza zakończenie programu.


```C++
bool playAgain() {
    char choice;
    cout<<endl;
    cout << "Czy chcesz zagrac ponownie? (T/N): ";
    cin >> choice;
    return (choice == 'T' || choice == 't'); // Sprawdzenie czy uzytkownik chce zagrac ponownie
}
```

# 5. *main()*

Główna funkcja main() kontroluje przebieg gry, pobiera ruchy gracza i komputera, sprawdza wynik gry oraz pytanie użytkownika o ponowną grę.

```C++
int main() {
    srand(time(0)); // Inicjalizacja generatora liczb losowych

    cout << "WITAJ W GRZE KAMIEN, PAPIER, NOZYCE!" << endl << endl;
    cout << "1 - kamien, 2 - papier, 3 - nozyce" << endl;

    bool play = true;
    while (play) {
        int playerMove = getPlayerMove();
        int computerMove = generateComputerMove();

        determineWinner(playerMove, computerMove); // Sprawdzenie wyniku gry

        play = playAgain(); // Czy uzytkownik chce zagrac ponownie?
        cout << endl;
    }

    return 0;
}
```

## Autor: Oskar Józefowski 2AP
