#include "Game.h"
Game::Game(int* arr)
{
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> temp;
        this->game.push_back(temp);
        for (int j = 0; j < 9; j++)
        {
            int tempInt = arr[i * 9 + j];
            this->game[i].push_back(tempInt);
        }
    }
}

Game::Game(Game* g)
{

    std::vector<std::vector<int>> cp;
    for (int i = 0; i < 9; i++)
    {
        cp.push_back(std::vector<int>());
        for (int j = 0; j < 9; j++)
        {
            cp[i].push_back(g->game[i][j]);
        }
    }
    this->game = cp;

}

Game::Game()
{
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> temp;
        this->game.push_back(temp);
        for (int j = 0; j < 9; j++)
        {
            this->game[i].push_back(0);
        }
    }
}

std::vector<std::vector<int>> Game::getGame()
{
    return this->game;
}

void Game::printBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << "____";
        }
        std::cout << std::endl;
        for (int j = 0; j < 9; j++)
        {
            std::cout << " | " << game[i][j];
        }
        std::cout << std::endl;
    }
}

void Game::gameEdit(int x, int y, int num)
{
    if (x >= 0 && x < 9 && y>=0 && y < 9 && num>0 && num <= 9)
    {
        this->game[x][y] = num;
    }
}
