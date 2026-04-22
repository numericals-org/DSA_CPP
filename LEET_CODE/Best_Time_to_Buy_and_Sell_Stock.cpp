#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;

        for(int n =0; n<prices.size(); n++){
            if(prices[n]< min){
                min = prices[n];
            }
            profit = max(profit, prices[n]-min);
        }

        return profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    
    Solution s;
    int res = s.maxProfit(prices);

    cout << res;

    return 0;
}