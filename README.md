# ***Dokumentacja***

![screenshot.png](/Assets/screenshot.png)

# Spis funkcji
1. imie_pracownika()
2. nazwisko_pracownika()
3. wprowadz_stanowisko()
4. generuj_haslo()
5. main()


# Opis funkcji 

# 1. *imie_pracownika()*

Funkcja służy do pobierania imienia pracownika od użytkownika. Po wywołaniu funkcji, użytkownik zostanie poproszony o wprowadzenie imienia, a następnie zostanie ono zwrócone

```C++
string imie_pracownika(string imie)
{

    cout<<"Dane Pracownika: "<<endl<<endl;
    cout<<"Imie:     "<<"   ";
    cin>>imie;

    return imie;

}
```
# 2. *nazwisko_pracownika()*

Ta funkcja służy do pobierania nazwiska pracownika od użytkownika. Po wywołaniu funkcji, użytkownik zostanie poproszony o wprowadzenie nazwiska, a następnie zostanie ono zwrócone

```C++
string nazwisko_pracownika(string nazwisko){
    cout<<"Nazwisko: "<<"   ";
    cin>>nazwisko;

    return nazwisko;
}
```
# 3. *wprowadz_stanowisko()*

Ta funkcja służy do pobierania informacji od użytkownika na temat stanowiska, jakie pełni w firmie. Na początku funkcja wyświetla listę stanowisk, z której użytkownik może wybrać odpowiednie. Następnie, użytkownik jest proszony o wprowadzenie numeru odpowiadającego wybranemu stanowisku. Wprowadzona wartość jest przypisywana do zmiennej stanowisko. W zależności od wyboru użytkownika, wartość zmiennej stanowisko zostanie przypisana jednemu z czterech dostępnych stanowisk ("Kierownik", "Starszy programista", "Młodszy programista" lub "Tester"). Ostatecznie, funkcja zwraca wybrane stanowisko.

```C++
string wprowadz_stanowisko( string stanowisko) {

    cout<<endl;
    cout<<"1.Kierownik"<<endl;
    cout<<"2.Starszy programista"<<endl;
    cout<<"3.Mlodszy programista"<<endl;
    cout<<"4.Tester"<<endl<<endl;

     cout<<"Wybierz stanowisko: "<<endl<<endl;
     cin>>stanowisko;

        if(stanowisko == "1"){
            stanowisko="Kierownik";
            }
            else if(stanowisko == "2"){
            stanowisko="Starszy programista";
            }
            else if(stanowisko == "3"){
            stanowisko="Mlodszy programista";
                }
                else {
                stanowisko="Tester";
                    }

    return stanowisko;

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
