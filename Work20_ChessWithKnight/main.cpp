#include <iostream>
#include <string>
using namespace std;

int columnNameToNumber(char c);
string coordsToString(int x, int y);
bool checkByBishop(int x, int y, int Bx, int By);
bool checkByQueen(int x, int y, int Qx, int Qy);
bool checkByKnight(int x, int y, int Kx, int Ky);

int main()
{
    setlocale(LC_ALL, "rus");
    int y;
    char c;
    cout << "Введите позицию черного короля: " << endl;
    cin >> c;
    cin >> y;
    int x = columnNameToNumber(c);
    coordsToString(x, y);
    if (checkByBishop(x, y, 1, 1)) 
        cout << "Шах от Ладьи" << endl;
    if (checkByKnight(x, y, 1, 6))
        cout << "Шах от Коня" << endl;
    else
        cout << "Шаха нет" << endl;
    return 0;
}


int columnNameToNumber(char c)
{
    int x;
    return 1 + c - (c <= 'H' ? 'A' : 'a');
}

string coordsToString(int x, int y)
{
    char c = 'A' + x - 1;
    string s = "";
    s += c;
    return s + to_string(y);
}

bool checkByQueen(int x, int y, int Qx, int Qy)
{
    return (x == Qx || y == Qy || abs(Qy - y) == abs(Qx - x));
}

bool checkByBishop(int x, int y, int Bx, int By)
{
    return (abs(By - y) == abs(Bx - x));
}

bool checkByKnight(int x, int y, int Kx, int Ky)
{
    return ((x == Kx + 1) && (y == Ky + 2) || (x == Kx + 2) && (y == Ky + 1) || 
            (x == Kx + 2) && (y == Ky - 1) || (x == Kx + 1) && (y == Ky - 2) || 
            (x == Kx - 1) && (y == Ky - 2) || (x == Kx - 2) && (y == Ky - 1) || 
            (x == Kx - 2) && (y == Ky + 1) || (x == Kx - 1) && (y == Ky + 2));
}