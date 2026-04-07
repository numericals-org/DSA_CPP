#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result(nums.size());

    int pre= 1, post =1;

    for(int i =0; i<nums.size(); i++){
        result[i] = pre;
        pre *= nums[i];
    }

    for(int i = nums.size() -1; i>=0; i--){
        result[i] *= post;
        post *= nums[i];
    }

    return 0;
}