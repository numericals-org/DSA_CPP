#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int row, int col, int &value)
    {
        grid[row][col] = 0;
        value++;

        if (row - 1 >= 0 && grid[row - 1][col] == 1)
        {
            dfs(grid, row - 1, col, value);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == 1)
        {
            dfs(grid, row, col - 1, value);
        }
        if (row + 1 < grid.size() && grid[row + 1][col] == 1)
        {
            dfs(grid, row + 1, col, value);
        }
        if (col + 1 < grid[0].size() && grid[row][col + 1] == 1)
        {
            dfs(grid, row, col + 1, value);
        }
    };
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int area = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    int value = 0; 
                    dfs(grid, row, col, value);
                    area = max(value, area);
                }
            }
        }

        return area;
    }
};

int main(){

    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;

    int val = s.maxAreaOfIsland(grid);

    cout << val << endl;

    return 0;
}