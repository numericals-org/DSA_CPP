#include <iostream>
using namespace std;

bool main()
{

    string s = "anagram", t = "nagaram";

    if (s.length() != t.length())
    {
        return false;
    }
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

// why pick this approach?
// This approach uses a counting method to determine if two strings are anagrams. It first checks
// if the lengths of the two strings are different, 
// in which case they cannot be anagrams and it returns false.
// Then, it initializes an array of size 26 to count the occurrences of each character in the strings. 
// It iterates through both strings simultaneously, incrementing the count for characters in the first string and decrementing for characters in the second string. 
// Finally, it checks if all counts are zero, which would indicate that the two strings are anagrams of each other. 
// This approach has a time complexity of O(n) and a space complexity of O(1) since the count array is of fixed size.