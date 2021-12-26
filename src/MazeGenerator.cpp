#include "../headers/MazeGenerator.h"
#include <random>
#include <ctime>
#include <array>

struct vec2
{
    int x, y;
};

std::vector<Direction> GetFreeCells(int cellX, int cellY, bool **visited, int sizeX, int sizeY)
{
    std::vector<Direction> out;
    out.reserve(4);

    vec2 dirs[] = {{cellX, cellY - 1},
                   {cellX, cellY + 1},
                   {cellX + 1, cellY},
                   {cellX - 1, cellY}};
    for (int i = 0; i < 4; i++)
    {
        if (dirs[i].x < sizeX && dirs[i].x > -1 && dirs[i].y < sizeY && dirs[i].y > -1)
            if (!visited[dirs[i].x][dirs[i].y])
                out.push_back((Direction)i);
    }
    return out;
}

MazeCell **GenerateMaze(int sizeX, int sizeY, int startCellX, int startCellY, unsigned int seed)
{
    std::stack<MazeCell *> generatedCells;
    MazeCell **maze = new MazeCell *[sizeX];
    bool **visited = new bool *[sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        maze[i] = new MazeCell[sizeY];
        visited[i] = new bool[sizeY];
        for (int j = 0; j < sizeY; j++)
        {
            visited[i][j] = false;
            maze[i][j].x = i;
            maze[i][j].y = j;
        }
    }
    std::mt19937 randomGen(seed);
    std::uniform_int_distribution<int> dist(0, 4);

    generatedCells.push(&maze[startCellX][startCellY]);

    while (!generatedCells.empty())
    {
        MazeCell *currentCell = generatedCells.top();
        visited[currentCell->x][currentCell->y] = true;
        const std::vector<Direction> freeCells = GetFreeCells(currentCell->x, currentCell->y, visited, sizeX, sizeY);
        if (freeCells.size() == 0)
        {
            //backtrack
            generatedCells.pop();
            continue;
        }
        else
        {
            Direction dir = freeCells[dist(randomGen) % freeCells.size()];
            int cellX = currentCell->x;
            int cellY = currentCell->y;
            vec2 dirs[] = {{cellX, cellY - 1},
                           {cellX, cellY + 1},
                           {cellX + 1, cellY},
                           {cellX - 1, cellY}};
            // ConstructTheWall
            currentCell->wall[dir] = false;
            auto &nextCell = maze[dirs[(int)dir].x][dirs[int(dir)].y];
            if (dir == UP)
            {
                nextCell.wall[DOWN] = false;
            }
            else if (dir == DOWN)
            {
                nextCell.wall[UP] = false;
            }
            else if (dir == RIGHT)
            {
                nextCell.wall[LEFT] = false;
            }
            else if (dir == LEFT)
            {
                nextCell.wall[RIGHT] = false;
            }

            generatedCells.push(&nextCell);
        }
    }

    for (int i = 0; i < sizeX; i++)
        delete[] visited[i];
    delete[] visited;
    return maze;
}
