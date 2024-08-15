#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool pairCompare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int> > tt(N);

    for(int i = 0; i < N; i++)
    {
        cin >> tt[i].first;
        cin >> tt[i].second;
    }

    sort(tt.begin(), tt.end(), pairCompare);

    stack<int> s;
    s.push(tt[0].second);

    for(int i = 1; i < N; i++)
    {
        if(s.top() <= tt[i].first)
            s.push(tt[i].second);
    }

    cout << s.size() << "\n";

    return 0;
}