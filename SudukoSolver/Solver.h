#pragma once
#include <vector>
#include "Game.h"

class Solver
{
	
public:
	Solver();
	
	bool solve(Game game, int x, int y);

	//check if num can be in certain coordinate
	bool checkSpace(Game g, int x, int y, int num);

	//gets index and returns which square it is
	int indexToSquare(int x, int y);

	

	std::vector<int> getRow(Game g, int x);
	std::vector<int> getColumn(Game g, int y);
	std::vector<int> getSquare(Game g, int x);
};