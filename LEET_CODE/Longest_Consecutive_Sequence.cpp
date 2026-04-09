#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> n(nums.begin(), nums.end());
        int longest =0;

        for (int num : n)
        {
            if (n.find(num - 1) == n.end())
            {
                int current = num;
                int count = 1;

                // expand forward
                while (n.find(current + 1) != n.end())
                {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

int main()
{
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    solution s;

    int length = s.longestConsecutive(nums);

    cout << length;

    return 0;
}