#include <iostream>
using namespace std;

int main(){

    int arr[5] = {4, 2, 7, 1, 9};
    int key = 7;

    for(int i = 0; i < 5; i++){

        if(arr[i] == key){
            cout << "Element found at index " << i << endl;
            return 0;
        }
    }

    cout << "Element not found" << endl;
}