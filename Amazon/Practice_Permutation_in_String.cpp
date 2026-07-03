#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
        return false;
       }

       vector<int> s1Map(26, 0);
       vector<int> s2Map(26, 0);

       for(int i =0; i <s1.length(); i++){
        s1Map[s1[i]-'a']++;
        s2Map[s2[i]-'a']++;
       }

       for(int i =0; i <s2.length() - s1.length(); i++){
        if(s1Map == s2Map){
            return true;
        }
        s2Map[s2[i + s1.length()]-'a']++;
        s2Map[s2[i]-'a']--;
       }

       return s1Map == s2Map;
    }
};

int main() {
    return 0;
}