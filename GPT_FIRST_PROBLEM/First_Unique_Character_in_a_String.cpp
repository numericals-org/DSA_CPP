#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    string s = "leetcode";
    unordered_map<char, int> charCount;

    for(char ch: s){
        charCount[ch]++;
    }

    for(int i = 0; i < s.length(); i++){
        if(charCount[s[i]] == 1){
            cout << "First unique character: " << s[i] << endl;
            return 0;
        }
    }
    cout << "No unique character found." << endl;
    return 0;
}