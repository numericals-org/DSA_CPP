#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, queue<pair<int, int>> &que, int &fresh)
    {
        int min = 0;

        while (!que.empty())
        {
            int size = que.size();
            bool changed = false;

            for (int i = 0; i < size; i++)
            {
                auto [row, col] = que.front();
                que.pop();

                if (row - 1 >= 0 && grid[row-1][col] == 1)
                {
                    grid[row-1][col] = 2;
                    changed = true;
                    fresh--;                 
                    que.push({row-1, col});
                }
                if (row + 1 < grid.size() && grid[row+1][col] == 1)
                {
                    grid[row+1][col] = 2;
                    changed = true;
                    fresh--;                 
                    que.push({row+1, col});
                }
                if (col - 1 >= 0 && grid[row][col-1] == 1)
                {
                    grid[row][col-1] = 2;
                    changed = true;
                    fresh--;                 
                    que.push({row, col-1});
                }
                if (col + 1 < grid[0].size() && grid[row][col+1] == 1)
                {
                    grid[row][col+1] = 2;
                    changed = true;
                    fresh--;                 
                    que.push({row, col+1});
                }
            }
            if(changed){
                min++;
            }
        }

        return min;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {

        queue<pair<int, int>> que;
        int fresh = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 2)
                {
                    que.push({row, col});
                }
                if (grid[row][col] == 1)
                {
                    fresh++;
                }
            }
        }

        int result = 0;
        result = bfs(grid, que, fresh);

        if(fresh > 0){
            return -1;
        }

        return result;
    }
};

int main()
{
    return 0;
}