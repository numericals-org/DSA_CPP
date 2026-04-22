#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n = s1.size(), m = s2.size();
//         if (n > m) return false;

//         vector<int> freq(26, 0);

//         // build requirement
//         for (char c : s1) freq[c - 'a']++;

//         int left = 0, right = 0;

//         while (right < m) {
//             // include right char
//             freq[s2[right] - 'a']--;

//             // if invalid (count < 0), shrink from left
//             while (freq[s2[right] - 'a'] < 0) {
//                 freq[s2[left] - 'a']++;
//                 left++;
//             }

//             // valid window size
//             if (right - left + 1 == n) return true;

//             right++;
//         }

//         return false;
//     }
// };

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
       if(s1.length() > s2.length()){
        return false;
       }

       vector<int> s1Map(26, 0);
       vector<int> s2Map(26, 0);

       for(int i =0; i <s1.length(); i++){
        s1Map[s1[i]-'a']++;
        s2Map[s2[i]-'a']++;
       }

       for(int i =0; i <s2.length() - s1.length(); i++){
        if(s1Map == s2Map){
            return true;
        }
        s2Map[s2[i + s1.length()]-'a']++;
        s2Map[s2[i]-'a']--;
       }

       return s1Map == s2Map;
    }
};

int main()
{
    string s1 = "ab", s2 = "eidbaooo";

    Solution s;
    bool res = s.checkInclusion(s1, s2);

    cout << res;

    return 0;
}