#include <iostream>
using namespace std;

int Recursion(int n)
{
   if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return Recursion(n-1) + Recursion(n-2);
}

int main()
{
    int x;

    cout << "Enter a integer";
    cin >> x;

    int a = Recursion(x);

    cout << a;
}