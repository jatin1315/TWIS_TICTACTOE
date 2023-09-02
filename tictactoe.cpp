#include <iostream>
using namespace std;
const int SIZE = 3;
char grid[SIZE][SIZE];
void initializeboard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = ' ';
        }
    }
}
void Griddisplay() {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
            cout<< "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << grid[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}
bool checkWin(char symbol) {
    for (int i = 0; i < SIZE; ++i) {
        if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
            return true;

        if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
            return true;
    }
    if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
        return true;

    if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
        return true;

    return false;
}
bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}
bool makeMove(char symbol) {
    int cell;
    cout << "Player " << symbol << ", enter the cell number (1-9): ";
    cin >> cell;

    int row = (cell - 1) / SIZE;
    int col = (cell - 1) % SIZE;

    if (cell < 1 || cell > 9 || grid[row][col] != ' ') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    grid[row][col] = symbol;
    return true;
}
char getCurrentPlayer(int move) {
    return (move % 2 == 0) ? 'O' : 'X';
}

int main() {
    initializeboard();
    int move = 0;

    while (true) {
        Griddisplay();
        char currentPlayer = getCurrentPlayer(move);

        if (makeMove(currentPlayer)) {
            if (checkWin(currentPlayer)) {
                Griddisplay();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw()) {
                Griddisplay();
                cout << "It's a draw!\n";
                break;
            }
            move++;
        }
    }

    return 0;
}