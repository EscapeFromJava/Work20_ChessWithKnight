#include "Header.h"

const int SIZE = 10;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Сколько белых фигур выставить на поле? ";
    int numberOfFigures; 
    cin >> numberOfFigures;
    cout << "Расставьте белые фигуры: " << endl;
    string history, lastInput;
    ChessFigure arrChessFigure[SIZE], WhiteByshop, WhiteQueen, WhiteKnight;
    for (int i = 0; i < numberOfFigures; i++) {
         int count = 0, volWhiteByshop = 0, volWhiteQueen = 0, volWhiteKnight = 0;
         while (count != 1) {
                cout << "Выберите " << i + 1 << " шахматную фигуру [1 - Слон, 2 - Королева, 3 - Конь]: ";
                int x;
                cin >> x;
                if (x == 1) {
                    if (volWhiteByshop == 1) {
                        cout << "Превышен лимит выбранной фигуры" << endl;
                        continue;
                    }
                    WhiteByshop = inputChessFigure();
                    WhiteByshop.name = "WhiteByshop";
                    arrChessFigure[i] = WhiteByshop;
                    lastInput = WhiteByshop.x + to_string(WhiteByshop.y);
                    if (history.find(lastInput) != string::npos) {
                        cout << "Поле занято другой фигурой" << endl;
                        continue;
                    }
                    count++;
                    volWhiteByshop++;
                }
                if (x == 2) {
                    if (volWhiteQueen == 1) {
                        cout << "Превышен лимит выбранной фигуры" << endl;
                        continue;
                    }
                    WhiteQueen = inputChessFigure();
                    WhiteQueen.name = "WhiteQueen";
                    arrChessFigure[i] = WhiteQueen;
                    lastInput = WhiteQueen.x + to_string(WhiteQueen.y);
                    if (history.find(lastInput) != string::npos) {
                        cout << "Поле занято другой фигурой" << endl;
                        continue;
                    }
                    count++;
                    volWhiteQueen++;
                }
                if (x == 3) {
                    if (volWhiteKnight == 1) {
                        cout << "Превышен лимит выбранной фигуры" << endl;
                        continue;
                    }
                    WhiteKnight = inputChessFigure();
                    WhiteKnight.name = "WhiteKnight";
                    arrChessFigure[i] = WhiteKnight;
                    lastInput = WhiteKnight.x + to_string(WhiteKnight.y);
                    if (history.find(lastInput) != string::npos) {
                        cout << "Поле занято другой фигурой" << endl;
                        continue;
                    }
                    count++;
                    volWhiteKnight;
                } 
                history += lastInput;
         }
    }
   
    ChessFigure BlackKing;
    bool flagKing = false;
    while (flagKing == false) {
        cout << "Укажите позицию черного короля: " << endl;
        BlackKing = inputChessFigure();
        BlackKing.name = "BlackKing";
        lastInput = BlackKing.x + to_string(BlackKing.y);
        if (history.find(lastInput) != string::npos) {
            cout << "Поле занято другой фигурой" << endl;
            continue;
        }
        arrChessFigure[numberOfFigures] = BlackKing;
        flagKing = true;
    }
    printArr(arrChessFigure, numberOfFigures + 1);
    bool flag = true;
    if (checkByBishop(BlackKing.x, BlackKing.y, WhiteByshop.x, WhiteByshop.y)) {
        cout << "Шах от белого слона" << endl;
        flag = false;
    }
    if (checkByQueen(BlackKing.x, BlackKing.y, WhiteQueen.x, WhiteQueen.y)) {
        cout << "Шах от белой королевы" << endl;
        flag = false;
    }
    if (checkByKnight(BlackKing.x, BlackKing.y, WhiteKnight.x, WhiteKnight.y)) {
        cout << "Шах от белого коня" << endl;
        flag = false;
    }
    if (flag) {
        cout << "Шаха нет" << endl;
    }
    return 0;
}


