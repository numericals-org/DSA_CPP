#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 4, 7, 9};
    int n = 5;
    int key = 7;

    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == key)
        {
            cout << "Element found at index " << mid;
            return 0;
        }

        else if(arr[mid] < key)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    cout << "Element not found";
}