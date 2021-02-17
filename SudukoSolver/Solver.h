#pragma once
#include <vector>
#include "Game.h"
class Solver
{
	Game* game;
public:
	Solver(Game* g);

	//gets unused numbers fo certain square
	std::vector<int> getUnusedNums(std::vector<int> vect);

	//adds numbers to game if they are the only num possible for certain spot
	void simpleTest();

	//TODO: add number if only 1 number is possible in a row, col or square
	void addNums();
	
	//checks if game is valid in current state
	bool checkGame();

	bool check(std::vector<int> vect);

	bool checkSpace(int x, int y);


	int indexToSquare(int x, int y);

	std::vector<int> getRow(int x);
	std::vector<int> getColumn(int y);
	std::vector<int> getSquare(int x);
};