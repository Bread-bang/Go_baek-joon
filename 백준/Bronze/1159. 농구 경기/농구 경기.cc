#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string name, result;
    cin >> N;

    map<char, int> m;
    for(int i = 0; i < N; i++)
    {
        cin >> name;
        if(m.find(name[0]) != m.end())
        {
            m[name[0]]++;
            if(m[name[0]] == 5)
                result.push_back(name[0]);
        }
        else
            m[name[0]] = 1;
    }

    if(result.size() == 0)
        cout << "PREDAJA" << endl;
    else
    {
        sort(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}