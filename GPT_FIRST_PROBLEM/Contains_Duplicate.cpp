#include <iostream>;
#include <unordered_set>;
using namespace std;

bool main()
{
    int nums[] = {1, 2, 3, 1};
    unordered_set<int> s;
    for (int num : nums)
    {
        if (s.find(num) != s.end())
        {
            return true;
        }
        else
        {
            s.insert(num);
        }
    }
    return false;
}

// why pick this approach?
// This approach uses an unordered_set to keep track of the numbers we have seen as we iterate through the array. The unordered_set allows for O(1) average time complexity for insertions and lookups, making it efficient for this problem. By checking if a number is already in the set before inserting it, we can quickly determine if there is a duplicate in the array. If we find a duplicate, we return true immediately. If we finish iterating through the array without finding any duplicates, we return false.

// Unordered_set is always includes the unique elements, so if we find a duplicate, it means that the number is already in the set, and we can return true. If we finish iterating through the array without finding any duplicates, it means that all numbers are unique, and we can return false.