#include <iostream>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            // odd length
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }

            // even length
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};

int main()
{
    string s = "abc";

    Solution SL;
    int result = SL.countSubstrings(s);

    cout << result << endl;

    return 0;
}