#include <iostream>
using namespace std;

int fib(int n, int memo[])
{
    if(n <= 1)
        return n;

    if(memo[n] != -1)
        return memo[n];

    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main()
{
    int n = 10;
    int memo[100];

    for(int i=0;i<100;i++)
        memo[i] = -1;

    cout << fib(n, memo);
}