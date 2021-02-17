#include "Solver.h"
#include "Game.h"
#include <algorithm> 

Solver::Solver(Game* g)
{
	this->game = g;
}

std::vector<int> Solver::getUnusedNums(std::vector<int> vect)
{
	std::vector<int> res;
	bool isUsed = false;
	for (int num = 1; num <= 9; num++)
	{
		for (int i = 0; i < vect.size(); i++)
		{
			if (vect[i] == num) 
			{
				isUsed = true;
				break;
			}
		}
		if (isUsed == false)
		{
			res.push_back(num);
		}
		isUsed = false;
	}
	return res;
}


void Solver::simpleTest()
{
	for (int i = 0; i < 3; i++)
	{
		this->addNums();
	}
	this->game->printBoard();

}

void Solver::addNums()
{
	///the point is i take a square, get its unused numbers, and check every number in all spots.
	/// if a number can only be in 1 spot, i pop it in
	for (int i = 0; i < 9; i++)
	{
		std::vector<std::vector<int>> tempBoard = this->game->getGame();
		std::vector<int> unused = this->getUnusedNums(this->getSquare(i));
		int x = (i / 3) * 3;
		int y = (i % 3) * 3;

		int tempX = 0;
		int tempY = 0;
		for (int j = 0; j < unused.size(); i++)
		{
			int countSpot = 0;
			for (int rows = x + 0; rows < x + 3; rows++)
			{
				for (int cols = y + 0; cols < y + 3; cols++)
				{
					
					if (tempBoard[rows][cols] == 0)
					{
						tempBoard[rows][cols] = unused[j];
						if (this->checkSpace(rows, cols))
						{
							countSpot++;
							tempX = rows;
							tempY = cols;
						}

						tempBoard[rows][cols] = 0;

						if (countSpot > 1)
						{
							break;
						}
					}
					if (countSpot > 1)
					{
						break;
					}
				}
			}
			if (countSpot == 1)
			{
				this->game->gameEdit(tempX, tempY, unused[j]);
				tempBoard[tempX][tempY] = unused[j];
			}
			tempX = 0;
			tempY = 0;
			countSpot = 0;
		}
	}





}

bool Solver::checkGame()
{
	std::vector<std::vector<int>> tempBoard = this->game->getGame();
	

	bool res = true;
	for (int i = 0; i < 9; i++)
	{
		if (!(check(this->getRow(i)) && check(this->getColumn(i)) && check(this->getSquare(i)))) 
		{
			return false;
		}
	}

	return true;
}

bool Solver::check(std::vector<int> vect)
{
	sort(vect.begin(), vect.end());
	int temp = 0;
	for (int i = 0; i < 9; i++) 
	{
		if (vect[i] != 0)
		{
			if (temp == vect[i])
			{
				return false;
			}
			temp = vect[i];
		}
	}
	return true;
}

int Solver::indexToSquare(int x, int y)
{
	return x - (x % 3) + y / 3;
}

bool Solver::checkSpace(int x, int y)
{
	return check(this->getRow(x)) && check(this->getColumn(y)) && check(this->getSquare(indexToSquare(x, y)));
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

