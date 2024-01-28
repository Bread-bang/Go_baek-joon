#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

int main() {

    string input;
    cin >> input;

    map<char, int> m;
    char c;
    for(int i = 0; i < input.size(); i++)
    {
        c = tolower(input[i]);
        if(m.find(c) == m.end())
            m[c] = 1;
        else
            m[c]++;
    }

    vector<pair<char, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), comp);
    
    if(v[0].second == v[1].second)
        cout << "?" << endl;
    else 
        cout << (char)toupper(v.begin()->first) << endl;

    return 0;
}