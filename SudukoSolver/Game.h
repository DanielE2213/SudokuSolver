#pragma once
#include <vector>
#include <iostream>
class Game
{
	std::vector<std::vector<int>> game;
public:
	//Constructor
	Game(int* arr);
	Game();
	//returns the game as a 2d vector
	std::vector<std::vector<int>> getGame();

	//prints board
	void printBoard();

	//edits game
	void gameEdit(int x, int y, int num);
	
};