#pragma once
#include <iostream>
#include <string>

using namespace std;

struct ChessFigure {
	char x;
	int y = 0;
};

ChessFigure inputChessFigure();
int columnNameToNumber(char c);
string coordsToString(int x, int y);
bool checkByBishop(int x, int y, int Bx, int By);
bool checkByQueen(int x, int y, int Qx, int Qy);
bool checkByKnight(int x, int y, int Kx, int Ky);