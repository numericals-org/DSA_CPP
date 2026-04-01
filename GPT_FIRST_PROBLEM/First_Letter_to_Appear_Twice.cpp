#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    string s = "abccbaacz";
    unordered_set<char> seen;
    for (char ch:s){
        if(seen.find(ch) != seen.end()){
            cout << "First letter to appear twice: " << ch << endl;
            return 0;
        }
        seen.insert(ch);
    }
    return 0;
}