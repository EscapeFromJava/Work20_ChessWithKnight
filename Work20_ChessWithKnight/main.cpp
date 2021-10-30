#include "Header.h"

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Сколько белых фигур выставить на поле? ";
    int numberOfFigures;
    cin >> numberOfFigures;
    cout << "Расставьте белые фигуры: " << endl;
    string history, lastInput;
    ChessFigure WhiteByshop, WhiteQueen, WhiteKnight;
    int count = 1, volWhiteByshop = 0, volWhiteQueen = 0, volWhiteKnight = 0;
    while (count != (numberOfFigures + 1)) {
        cout << "Выберите " << count << " шахматную фигуру [1 - Слон, 2 - Королева, 3 - Конь]: ";
        int x;
        cin >> x;
        if (x == 1) {
            if (volWhiteByshop == 2) {
                cout << "Превышен лимит выбранной фигуры" << endl;
                continue;
            }
            WhiteByshop = inputChessFigure();
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
            lastInput = WhiteQueen.x + to_string(WhiteQueen.y);
            if (history.find(lastInput) != string::npos) {
                cout << "Поле занято другой фигурой" << endl;
                continue;
            }
            count++;
            volWhiteQueen++;
        }
        if (x == 3) {
            if (volWhiteKnight == 2) {
                cout << "Превышен лимит выбранной фигуры" << endl;
                continue;
            }
            WhiteKnight = inputChessFigure();
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
    ChessFigure BlackKing;
    bool flagKing = false;
    while (flagKing == false) {
        cout << "Укажите позицию черного короля: " << endl;
        BlackKing = inputChessFigure();
        lastInput = BlackKing.x + to_string(BlackKing.y);
        if (history.find(lastInput) != string::npos) {
            cout << "Поле занято другой фигурой" << endl;
            continue;
        }
        flagKing = true;
    }
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


