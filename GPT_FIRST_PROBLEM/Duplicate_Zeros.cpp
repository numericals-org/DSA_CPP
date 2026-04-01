#include <iostream>
#include <vector>
using namespace std;

vector<int> duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = n - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            if (i + 1 < n)
            {
                arr[i + 1] = 0;
            }
            i++;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    vector<int> result = duplicateZeros(arr);

     for (int i : result) {
        cout << i << " ";
    }

    return 0;
}