#pragma once
#include <vector>
#include <iostream>
#include <stack>

enum Direction
{
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3
};

struct MazeCell
{
    bool wall[4] = {true, true, true, true};
    int x, y;
};

MazeCell **GenerateMaze(int sizeX, int sizeY, int startCellX, int startCellY, unsigned int seed = 0);
