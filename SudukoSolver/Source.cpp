#include <stdio.h>
#include "Game.h"
#include "Solver.h"
int main() 
{
    int board[81] = {
                 4,0,1   ,2,9,0    ,0,7,5,
                 2,0,0   ,3,0,0    ,8,0,0,
                 0,7,0   ,0,8,0    ,0,0,6,

                 0,0,0   ,1,0,3    ,0,6,2,
                 1,0,5   ,0,0,0    ,4,0,3,
                 7,3,0   ,6,0,8    ,0,0,0,

                 6,0,0   ,0,2,0    ,0,3,0,
                 0,0,7   ,0,0,1    ,0,0,4,
                 8,9,0   ,0,6,5    ,1,0,7
    };
	int* boardPointer = board;
	Game game = Game(boardPointer);
	Solver s = Solver();
	s.solve(game, 0,0);
	return 0;
}