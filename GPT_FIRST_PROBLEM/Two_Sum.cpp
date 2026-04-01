#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> m;
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        int complement = target - nums[i];
        if (m.find(complement) != m.end())
        {
            cout << "Indices: " << m[complement] << " and " << i << endl;
            return 0;
        }
        m[nums[i]] = i;
    }
    cout << "No two sum solution found." << endl;
    return 0;
}