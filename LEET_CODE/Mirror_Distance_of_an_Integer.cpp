#include<iostream>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int reverse =0, x=n;
         while (x > 0)
            {
                reverse = reverse * 10 +  x % 10;
                x /= 10;
            }
        
            return abs(n - reverse);
    }
};

int main() {
    int n = 25;
    Solution s;
    int result = s.mirrorDistance(n);

    cout << result;

    return 0;
}