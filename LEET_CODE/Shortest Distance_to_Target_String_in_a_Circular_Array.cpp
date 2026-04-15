#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (words[i] == target)
            {
                int dist = abs(i - startIndex);
                dist = min(dist, n - dist); // circular distance
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    string target = "hello";
    int startIndex = 1;

    Solution s;
    int result = s.closestTarget(words, target, startIndex);

    cout << result << endl;

    return 0;
}
