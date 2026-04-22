#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> occurance(26, 0);
        int left = 0, ans = 0, max_occurance = 0;

        for (int right = 0; right < s.size(); right++)
        {
            max_occurance = max(max_occurance, ++occurance[s[right] - 'A']);

            if (right - left + 1 - max_occurance > k)
            {
                occurance[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    return 0;
}