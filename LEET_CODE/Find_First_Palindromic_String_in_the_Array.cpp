#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (string w : words)
        {
            int left = 0, right = w.length() - 1;
            bool isPal = true;

            while (left < right)
            {
                while (left < right && !isalnum(w[left]))
                {
                    left++;
                }
                while (left < right && !isalnum(w[right]))
                {
                    right--;
                }

                char chL = tolower(w[left]);
                char chR = tolower(w[right]);
                if (chL != chR)
                {
                    isPal = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPal)
            {
                return w;
            }
        }

        return "";
    }
};

int main()
{

    vector<string> words = {"abc", "car", "ada", "racecar", "cool"};

    Solution s;
    string result = s.firstPalindrome(words);

    cout << result << endl;

    return 0;
};