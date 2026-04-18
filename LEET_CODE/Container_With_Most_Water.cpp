#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, left = 0, right = height.size() -1;

        while(left<right){
            int area = min(height[left], height[right]) * (right - left);
            result = max(result, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right --;
            }
        }

        return result;
    }
};

int main() {

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;
    int res = s.maxArea(height);
    cout << res;
    return 0;
}