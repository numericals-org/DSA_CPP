#include<iostream>
#include<vector>
using namespace std;

// more optimal approach
//  int left = 0;
//     int right = arr.size() - k;

//     while (left < right) {
//         int mid = left + (right - left) / 2;

//         if (x - arr[mid] > arr[mid + k] - x) {
//             left = mid + 1;
//         } else {
//             right = mid;
//         }
//     }

//     return vector<int>(arr.begin() + left, arr.begin() + left + k);

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0, right=arr.size() -1;
        vector<int> re;

        while(right - left + 1 > k){
            if(abs(arr[left] - x) <= abs(arr[right] - x)){
                right--;
            }else{
                left++;
            }
        }

        for(int i = left; i<=right; i++){
            re.push_back(arr[i]);
        }

        return re;
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 3;

    Solution s;
    vector<int> result = s.findClosestElements(arr, k, x);

    for(int i=0; i<result.size(); i++){
        cout<< result[i] << endl;
    }

    return 0;
}