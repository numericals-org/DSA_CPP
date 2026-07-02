#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    bool containsDuplicate(vector<int>& nums){
        unordered_map<int, int> m;
        for(int i =0; i <= nums.size() -1; i++){
            if(m.count(nums[i])){
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main () {
    vector<int> nums = {1,2,3,6};
    Solution s;

    bool output = s.Contains_Duplicate(nums) ;

    cout << output << endl;

    return 0;
}