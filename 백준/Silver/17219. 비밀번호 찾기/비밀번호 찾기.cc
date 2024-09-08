#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    cin.ignore();

    unordered_map<string, string> um;

    while(N--)
    {
        string url, pw;
        cin >> url >> pw;

        um.emplace(url, pw);
    }
    cin.ignore();

    while(M--)
    {
        string url;
        getline(cin, url);

        if(um.find(url) != um.end())
            cout << um[url] << "\n";
    }

    return 0;
}