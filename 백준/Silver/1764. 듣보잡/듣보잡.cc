#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();

    map<string, int> m;

    while(N--)
    {
        string str;
        getline(cin, str);

        m[str] = 0;
    }
        
    while(M--)
    {
        string str;
        getline(cin, str);

        auto it = m.find(str);

        if(it != m.end())
        {
            it->second++;
        }
        else
        {
            m[str] = 0;
        }
    }

    int count = 0;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second > 0)
            count++;
    }
    cout << count << "\n";

    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second > 0)
            cout << it->first << "\n";
    }

    return 0;
}