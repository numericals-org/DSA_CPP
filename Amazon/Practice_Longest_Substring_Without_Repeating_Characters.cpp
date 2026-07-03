#include<iostream>
#include<unordered_set>
using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string str){
            unordered_set<char> ch;
            int left =0, maxlen =0;

            for(int right =0; right<str.size(); right++){
                while(ch.count(str[right])){
                    ch.erase(str[left]);
                    left++;
                }
                ch.insert(str[right]);
                maxlen = max(maxlen, right-left+1);
            }

            return maxlen;
        }
};

int main(){
    return 0;
}