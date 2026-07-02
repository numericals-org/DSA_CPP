#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
using namespace std;

class Solution{
    public:
    vector<int>topKFrequentElements(vector<int>& nums, int k){
        unordered_map<int, int>m;

        for(int i: nums){
            m[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto &it: m){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

int main() {

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution s;

    vector<int> output = s.topKFrequentElements(nums, k);

    for(int c: output){
        cout << c << endl;
    }

    return 0;
}