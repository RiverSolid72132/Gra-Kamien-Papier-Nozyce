#include <iostream>
#include <ctime>

using namespace std;

int generateComputerMove() {
    return rand() % 3 + 1; // Generowanie losowego ruchu komputera (1-3)
}

int getPlayerMove() {
    int move;
    cout << "Wybierz swoj ruch (1-3): ";
    cin >> move;
    cout<<endl;
    return move; // Pobieranie ruchu gracza z wejscia
}

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

bool playAgain() {
    char choice;
    cout<<endl;
    cout << "Czy chcesz zagrac ponownie? (T/N): ";
    cin >> choice;
    return (choice == 'T' || choice == 't'); // Sprawdzenie czy uzytkownik chce zagrac ponownie
}

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
