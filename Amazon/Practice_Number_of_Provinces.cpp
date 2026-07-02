#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, int city, vector<bool> &visited)
    {
        visited[city] = true;

        for (int i = 0; i < isConnected.size(); i++)
        {
            // cout << isConnected[city][i] << endl;
            if (isConnected[city][i] == 1 && !visited[i])
            {
                cout << "dfs loop" << i << endl;
                dfs(isConnected, i, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;

        for(int i =0; i < visited.size(); i++){
            if(visited[i] != true){
                dfs(isConnected, i, visited);
                cout << "loop" << i << endl;
                provinces++;
            }
        }

        return provinces;
    }
};

int
main()
{
    vector<vector<int>> isConnected = {
    {1,1,0},
    {1,1,0},
    {0,0,1}
};
    Solution s;

    int value = s.findCircleNum(isConnected);

    cout << value << endl;

    return 0;
}