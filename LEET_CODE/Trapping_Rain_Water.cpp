#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, leftMax = height[0], rightMax = height[right], total = 0;

        while(left<right){
            if(height[left]< height[right]){
                leftMax = max(leftMax, height[left]);
                if(leftMax - height[left]>0){
                    total = total + leftMax - height[left];
                }
                left++;
            }
            else{
                rightMax = max(rightMax, height[right]);
                if(rightMax - height[right]>0){
                    total = total + rightMax - height[right];
                }
                right--;
            }
        }

        return total;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;

    int res = s.trap(height);

    cout << res;

    return 0;
}