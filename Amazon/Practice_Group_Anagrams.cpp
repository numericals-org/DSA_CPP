#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> m;
        for(const string& str: strs){
            int ch[26]= {0};
            for(char c : str){
                ch[c - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++){
                key.push_back(ch[i]+'a');
            }
            m[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto &it: m){
            result.push_back(it.second);
        }
        return result;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution s;

    vector<vector<string>> result = s.groupAnagrams(strs);

    for(vector<string> s: result){
        for(string c: s){
            cout << c <<endl;
        }
    }

    return 0;
}