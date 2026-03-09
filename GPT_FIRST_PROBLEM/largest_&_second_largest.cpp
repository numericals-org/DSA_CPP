#include <iostream>
using namespace std;

int main(){
    int arr[5] = {3,7,2,9,1};

    int largest = arr[0];
    int second = -1;

    for(int i = 1; i < 5; i++){

        if(arr[i] > largest){
            second = largest;
            largest = arr[i];
        }

        else if(arr[i] > second && arr[i] != largest){
            second = arr[i];
        }
    }

    cout << "largest number" << largest;
    cout << "Second largest: " << second;
}