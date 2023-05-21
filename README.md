# ***Dokumentacja***

![screenshot.png](/Assets/screenshot.png)

# Spis funkcji
1. generateComputerMove()
2. getPlayerMove()
3. determineWinner()
4. generuj_haslo()
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

# 4. *generuj_haslo()*

Ta funkcja generuje losowe hasło o zadanej długości, z wykorzystaniem podanych przez użytkownika opcji



**dlugosc** : długość generowanego hasła

**male_litery** : określa, czy mają być wykorzystane małe litery

**wielkie_litery**: określa, czy mają być wykorzystane wielkie litery

**cyfry**: określa, czy mają być wykorzystane cyfry

**znaki_specjalne**: określa, czy mają być wykorzystane znaki specjalne



Funkcja tworzy string dostepne_znaki, który składa się z znaków wybranych przez użytkownika (zależnie od wartości flag). Następnie losuje indeksy z dostepne_znaki i dodaje odpowiednie znaki do zmiennej haslo. Ostatecznie funkcja zwraca wygenerowane hasło.

```C++
string generuj_haslo(int dlugosc, bool male_litery, bool wielkie_litery, bool cyfry, bool znaki_specjalne)
 {
    string haslo = "";
    string male_litery_str = "abcdefghijklmnopqrstuvwxyz";
    string wielkie_litery_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cyfry_str = "0123456789";
    string znaki_specjalne_str = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";

    string dostepne_znaki = "";
     if(male_litery) dostepne_znaki += male_litery_str;
    if (wielkie_litery) dostepne_znaki += wielkie_litery_str;
    if (cyfry) dostepne_znaki += cyfry_str;
    if (znaki_specjalne) dostepne_znaki += znaki_specjalne_str;

    int dostepne_znaki_dlugosc = dostepne_znaki.length();
    srand(time(0));
    for (int i = 0; i < dlugosc; i++) {
        int indeks = rand() % dostepne_znaki_dlugosc;
        haslo += dostepne_znaki[indeks];
    }
    return haslo;

}
```

# 5. *main()*

Ta funkcja zawiera funkcje imie_pracownika, nazwisko_pracownika, wprowadz_stanowisko i generuj_haslo. Funkcje te służą do wprowadzenia imienia, nazwiska, wyboru stanowiska oraz generowania hasła. W funkcji main, użytkownik jest proszony o podanie informacji potrzebnych do wygenerowania hasła, a następnie są one przekazywane do funkcji generuj_haslo, która generuje losowe hasło na podstawie podanych informacji. Następnie, funkcja main wyświetla wygenerowane hasło oraz informacje o pracowniku, w tym imię, nazwisko, stanowisko i wygenerowane hasło.

```C++
int main()
{
    string imie ;
    string nazwisko ;
    string stanowisko;

    int dlugosc;
    bool male_litery, wielkie_litery, cyfry, znaki_specjalne;

       imie = imie_pracownika(imie);
        nazwisko = nazwisko_pracownika(nazwisko);
        stanowisko = wprowadz_stanowisko(stanowisko);
        generuj_haslo(dlugosc, male_litery, wielkie_litery, cyfry, znaki_specjalne);


            cout << "Podaj dlugosc hasla: "<<endl<<endl;
                cin >> dlugosc;
            cout<<endl;

            cout << "Uzywac malych liter? (1-tak, 0-nie): "<<endl<<endl;
                cin>>male_litery;

            cout << "Uzywac wielkich liter? (1-tak, 0-nie): "<<endl<<endl;
                cin >> wielkie_litery;
            cout<<endl;

            cout << "Uzywac cyfr? (1-tak, 0-nie): "<<endl<<endl;
                cin >> cyfry;
            cout<<endl;

            cout << "Uzywac znakow specjalnych? (1-tak, 0-nie): "<<endl<<endl;
                cin >> znaki_specjalne;
            cout<<endl;

            string haslo = generuj_haslo(dlugosc, male_litery, wielkie_litery, cyfry, znaki_specjalne);
            cout << "Wygenerowane haslo: " << haslo << endl<<endl;

            cout<<"Dane pracownika: "<<imie<<", "<<nazwisko<<", "<<stanowisko<<", "<<haslo<<endl;


    return 0;
}
```

## Autor: Oskar Józefowski 2AP
