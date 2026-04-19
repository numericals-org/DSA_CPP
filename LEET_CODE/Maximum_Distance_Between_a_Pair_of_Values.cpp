#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int left = 0, right = 0, max_int = 0;
        while (left < nums1.size())
        {
            if (right >= nums2.size())
                break;

            if (nums1[left] <= nums2[right])
            {
                int val = right - left;
                max_int = max(max_int, val);
                right++;
            }
            else
            {
                left++;
            }
        }
        return max_int;
    }
};

int main()
{

    vector<int> nums1 = {8, 7, 3}, nums2 = {5, 5, 5, 5};
    Solution s;
    int res = s.maxDistance(nums1, nums2);

    cout << res;
    return 0;
}