#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left =0, total=0;

        for(int right =0; right < nums.size(); right++){
            total += nums[right];

            while (total >= target) {
                minLen = min(minLen, right - left + 1);
                total -= nums[left];
                left++;             
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;

    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution sol;

    int result = sol.minSubArrayLen(target, nums);

    cout << result << endl;
    return 0;
}