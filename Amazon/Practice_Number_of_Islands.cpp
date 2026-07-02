#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited){
        visited[row][col] = true;
        // for(int i=0; i<grid.size(); i++){
            if(row - 1 >= 0 && grid[row-1][col] == '1' && !visited[row - 1][col]){
                dfs(grid, row - 1, col, visited);
            }
            if (col - 1 >=0 && grid[row][col - 1] == '1' && !visited[row][col - 1]){
                dfs(grid, row, col - 1, visited);
            }
            if(row + 1 < grid.size() && grid[row + 1][col] == '1' && !visited[row+1][col]){
                dfs(grid, row + 1, col, visited);
            }
            if(col + 1 < grid[0].size() && grid[row][col+1] == '1' && !visited[row][col+1]){
                dfs(grid, row, col+1, visited);
            }
        // }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int island = 0;
        for(int i=0; i< visited.size(); i++){
            for(int j=0; j< visited[0].size(); j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    dfs(grid, i, j, visited);
                    island++;
                }
            }
        }

        return island;
    }
};

int main() {
    return 0;
}