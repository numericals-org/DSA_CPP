#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // Step 1: Build map (value → indices)
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;

        // Step 2: Process each query
        for (int q : queries)
        {
            int val = nums[q];
            vector<int> &a = mp[val];

            // If only one occurrence → no answer
            if (a.size() == 1)
            {
                res.push_back(-1);
                continue;
            }

            // Step 3: Find position of q using binary search
            int pos = lower_bound(a.begin(), a.end(), q) - a.begin();

            int ans = INT_MAX;

            int leftIdx = (pos - 1 + a.size()) % a.size();
            int left = a[leftIdx];

            int distLeft = abs(left - q);
            distLeft = min(distLeft, n - distLeft);

            ans = min(ans, distLeft);

            int rightIdx = (pos + 1) % a.size();
            int right = a[rightIdx];

            int distRight = abs(right - q);
            distRight = min(distRight, n - distRight);

            ans = min(ans, distRight);

            res.push_back(ans);
        }

        return res;
    }
};
int main()
{

    vector<int> nums = {1, 2, 3, 4}, queries = {0, 1, 2, 3};

    Solution s;
    vector<int> result = s.solveQueries(nums, queries);

    for (int r : result)
    {
        cout << r << endl;
    }

    return 0;
}