#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int getMinDistance(vector<int> &nums, int target, int start)
    {
        int minDist = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                minDist = min(minDist, abs(i - start));
            }
        }

        return minDist;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5, start = 3;
    Solution s;

    int res = s.getMinDistance(nums, target, start);

    cout << res << endl;

    return 0;
}