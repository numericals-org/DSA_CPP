#include <iostream>
#include <unordered_map>
using namespace std;
#include <String>

int main()
{
    string strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string, vector<string>> anagramGroups;

    for (string str : strs)
    {
        int n[26] = {0};
        for (char c : str)
        {
            n[c - 'a']++;
        }

        string key = "";
        for (int i = 0; i < 26; i++)
        {
             key.push_back(n[i] + 'a');
        }

        anagramGroups[key].push_back(str);
    };

    vector<vector<string>> result;
    for (auto &it : anagramGroups)
    {
        result.push_back(it.second);
    }

    return 0;
}

