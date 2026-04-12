#include <iostream>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;

        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
            {
                left++;
            }
            while (left < right && !isalnum(s[right]))
            {
                right--;
            }
            char chL = tolower(s[left]);
            char chR = tolower(s[right]);
            if (chL != chR)
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    return 0;
}