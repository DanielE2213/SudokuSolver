#include "Solver.h"
#include "Game.h"
#include <algorithm> 

Solver::Solver(Game* g)
{
	this->game = g;
}

int Solver::indexToSquare(int x, int y)
{
	return x - (x % 3) + y / 3;
}

bool Solver::checkSpace(int x, int y, int num)
{
	std::vector<int> row = this->getRow(x);
	std::vector<int> col = this->getColumn(y);
	std::vector<int> square = this->getSquare(this->indexToSquare(x,y));
	for (int i = 0; i < 9; i++)
	{
		if (num == row[i] or num == col[i] or num == square[i])
		{
			return false;
		}
	}
	return true;
}

std::vector<int> Solver::getRow(int x)
{
	
	if (x > 0 && x < 9)
	{
		return this->game->getGame()[x];
	}
	return std::vector<int>();
}

std::vector<int> Solver::getColumn(int y)
{
	if (y > 0 && y < 9)
	{
		std::vector<int> col;
		for (int i = 0; i < 9; i++)
		{
			col.push_back(this->game->getGame()[i][y]);
			return col;
		}
	}
	return std::vector<int>();
}

std::vector<int> Solver::getSquare(int num)
{
	int x = num / 3;
	int y = num % 3;
	if (x >= 0 && x < 9)
	{
		std::vector<int> square;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				square.push_back(this->game->getGame()[x*3 + i][y*3 + j]);	
			}
		}
		return square;
	}
	return std::vector<int>();
}

