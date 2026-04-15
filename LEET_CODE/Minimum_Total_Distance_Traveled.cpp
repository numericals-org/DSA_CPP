#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        unordered_map<int, int> f;

        for(vector<int> s: factory){
            f[s[0]] = s[1];
        }

        for(int r:robot){
            int factorys = 0;
        }

        return 0;
    }
};

int main() {

    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};

    Solution s;

    long result = s.minimumTotalDistance(robot, factory);

    cout << result << endl;

    return 0;
}