#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    unordered_map<int, int> frequencyMap;

    if (k == nums.size())
    {
        return 0;
    }

    for (int num : nums)
    {
        frequencyMap[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &it : frequencyMap)
    {
        pq.push({it.second, it.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> result;
    while (!pq.empty())
    {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return 0;
}