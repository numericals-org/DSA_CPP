#include <iostream>
using namespace std;

int main (){
    int num;
    int reverse = 0;

    cout << "Type a number: ";
    cin >> num;

    while (num != 0)
    {
       int digit = num % 10;
       reverse = reverse * 10 + digit;
       num = num / 10;
    }

    cout << reverse << endl;
}