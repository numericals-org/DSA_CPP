#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> map;

        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : map)
        {
            vector<int> &v = it.second;

            if (v.size() >= 3)
            {
                for (int i = 0; i + 2 < v.size(); i++)
                {
                    int dist = 2 * (v[i + 2] - v[i]);
                    ans = min(ans, dist);
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};

int main()
{

    vector<int> nums = {1, 1, 2, 3, 2, 1, 2};
    Solution s;

    int result = s.minimumDistance(nums);

    cout << result << endl;

    return 0;
}