#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> m = {{'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}};
    string input;

    cin >> input;
    for(char ch : input)
    {
        if(ch == '6' || ch == '9')
        {
            // ch = '9'
            char minimum_idx = m['6'] < m['9'] ? '6' : '9'; // 0
            m[minimum_idx]++;
        }
        else
            m[ch]++;
    }
    int max = -1;

    auto it = m.begin();
    while(it != m.end())
    {
        max = max > it->second ? max : it->second;
        ++it;
    }

    cout << max << endl;

    return 0;
}