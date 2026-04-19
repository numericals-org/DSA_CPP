#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> factors;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                factors.push_back(i);

                if (i != n / i)
                {
                    factors.push_back(n / i);
                }
            };
        }
        sort(factors.begin(), factors.end());

        if (k > factors.size())
            return -1;
        return factors[k - 1];
    }
};

int mai()
{
    int n = 12, k = 3;

    Solution s;
    int res = s.kthFactor(n, k);

    cout << res;

    return 0;
}