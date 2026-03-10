#include <iostream>
using namespace std;

int main(){
    int num[4] = {2,7,11,15};
    int target = 18;

     int n = sizeof(num) / sizeof(num[0]);

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(num[i] + num[j] == target){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}