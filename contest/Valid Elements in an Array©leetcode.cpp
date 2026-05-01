#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        while(true) {
            vector<int> res;

            if(nums.size() <= 2)
                return nums;

            res.push_back(nums[0]); // keep first

            bool changed = false;

            for(int i=1; i<nums.size()-1; i++) {
                if(nums[i] > nums[i-1] || nums[i] > nums[i+1]) {
                    res.push_back(nums[i]);
                } else {
                    changed = true; // removed something
                }
            }

            res.push_back(nums.back()); // keep last

            if(!changed)
                return res;

            nums = res; // repeat
        }
    }
};

int main () {
    vector<int> nums = {1,2,4,2,3,2};
    Solution s;

    vector<int> res = s.findValidElements(nums);

    for(int r:res){
        cout << r << ", ";
    }

    return 0;
}

