#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        return 1;

    int mask = 0;
    int temp = n;

    // Create mask like 111... (same length as n)
    while (temp > 0)
    {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return n ^ mask;
}