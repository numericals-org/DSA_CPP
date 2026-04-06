#include <iostream>
#include <unordered_map>
using namespace std;
#include <algorithm>

int main(){
    string strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string, vector<string>> m;
    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        m[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto &it : m)
    {
        result.push_back(it.second);
    }

    return 0;
}