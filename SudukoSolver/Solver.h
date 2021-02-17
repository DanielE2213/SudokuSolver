#pragma once
#include <vector>
#include "Game.h"
class Solver
{
	Game* game;
public:
	Solver(Game* g);




	bool checkSpace(int x, int y, int num);


	int indexToSquare(int x, int y);

	std::vector<int> getRow(int x);
	std::vector<int> getColumn(int y);
	std::vector<int> getSquare(int x);
};