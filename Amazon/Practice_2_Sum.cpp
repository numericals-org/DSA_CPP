#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> m;
            for(int i = 0; i<=nums.size() - 1; i++){
                int value = target - nums[i];
                if(m.find(value) != m.end()){
                    return {m[value], i};
                }
                m[nums[i]] = i;
            }
            return {};
        }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution s;

    vector<int> value = s.twoSum(nums, target);

    for(int value: value){
        cout << value << endl;
    }

    return 0;
}