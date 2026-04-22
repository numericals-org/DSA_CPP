#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left=0, right= colors.size() -1, max_int=0;

        while(left<colors.size()){
            if(colors[left] != colors[right]){
                max_int= max(max_int, abs(left -  right));
            }
            left++;
        }

        while(right>=0){
            if(colors[right] != colors[0]){
                max_int= max(max_int, abs(right -  0));
            }
            right--;
        }
        return max_int;
    }
};

int main() {
    vector<int> colors = {1,1,1,6,1,1,1};

    Solution s;
    int res = s.maxDistance(colors);

    cout << res;

    return 0;
}