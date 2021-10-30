#include "Header.h"

ChessFigure inputChessFigure()
{
	cout << "Укажите позицию: ";
	ChessFigure cf;
	cin >> cf.x >> cf.y;
    int x = columnNameToNumber(cf.x);
    coordsToString(x, cf.y);
	return cf;
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