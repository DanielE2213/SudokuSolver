#include "Solver.h"
#include <iostream>
#include "Game.h"
#include <algorithm> 


Solver::Solver()
{
}

bool Solver::solve(Game g,int x, int y)
{
	if (x == 8 and y == 9)
	{
		g.printBoard();
		return true;
	}

	if (y == 9)
	{
		y = 0;
		x++;
	}
	if (g.getGame()[x][y] != 0)
	{
		return this->solve(g, x, y + 1);
	}
	for (int i = 1; i <= 9; i++)
	{
		if (this->checkSpace(g, x, y, i))
		{
			g.gameEdit(x, y, i);
			if (this->solve(g, x, y + 1))
			{
				return true;
			}
			g.gameEdit(x, y, 0);
		}
		
	}
	return false;
}

int Solver::indexToSquare(int x, int y)
{
	return x - (x % 3) + y / 3;
}

bool Solver::checkSpace(Game g, int x, int y, int num)
{
	std::vector<int> row = this->getRow(g,x);
	std::vector<int> col = this->getColumn(g,y);
	std::vector<int> square = this->getSquare(g,this->indexToSquare(x,y));
	for (int i = 0; i < 9; i++)
	{
		if (num == row[i] or num == col[i] or num == square[i])
		{
			return false;
		}
	}
	return true;
}


std::vector<int> Solver::getRow(Game g,int x)
{
	
	if (x >= 0 && x < 9)
	{
		return g.getGame()[x];
	}
	return std::vector<int>();
}

std::vector<int> Solver::getColumn(Game g, int y)
{
	if (y >= 0 && y < 9)
	{
		std::vector<int> col;
		for (int i = 0; i < 9; i++)
		{
			col.push_back(g.getGame()[i][y]);
		}
		return col;
	}
	return std::vector<int>();
}

std::vector<int> Solver::getSquare(Game g, int num)
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
				square.push_back(g.getGame()[x*3 + i][y*3 + j]);	
			}
		}
		return square;
	}
	return std::vector<int>();
}

