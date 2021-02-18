#include <stdio.h>
#include "Game.h"
#include "Solver.h"
int main() 
{
    int board[81] = {
        0, 3, 0, 9, 1, 2, 4, 8, 6,
        8, 2, 0, 4, 5, 6, 1, 7, 3,
        6, 4, 1, 3, 8, 7, 0, 2, 5,

        9, 0, 3, 7, 4, 0, 2, 6, 8,
        2, 0, 6, 1, 3, 9, 7, 5, 4,
        4, 7, 5, 2, 6, 8, 3, 9, 1,

        7, 6, 4, 8, 9, 3, 0, 1, 2,
        3, 5, 2, 6, 0, 1, 0, 4, 9,
        1, 9, 0, 5, 2, 4, 6, 3, 7
}; 
	int* boardPointer = board;
	Game game = Game(boardPointer);
	Solver s = Solver();
	s.solve(game, 0,0);
	return 0;
}