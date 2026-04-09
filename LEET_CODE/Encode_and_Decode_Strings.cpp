#include <iostream>
#include <vector>
#include <string>
using namespace std;

class codec
{
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }
        string encodedString;
        for (string &s : strs)
        {
            encodedString += to_string(s.size()) + "#" + s;
        }
        return encodedString;
    };

public:
    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> decodedStrings;
        int i = 0;
        while (i < s.size())
        {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            decodedStrings.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return decodedStrings;
    }
};

int main()
{
    vector<string> strs = {"Hello", "World"};
    codec c;
    string encoded = c.encode(strs);
    cout << "Encoded string: " << encoded << endl;
    vector<string> decoded = c.decode(encoded);
    cout << "Decoded strings: ";
    for (const string &s : decoded)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}