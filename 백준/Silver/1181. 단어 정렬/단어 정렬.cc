#include <iostream>
#include <queue>

using namespace std;
using p_int_str = pair<int, string>;

struct Compare
{
    bool operator()(p_int_str& a, p_int_str& b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string str = "";
    priority_queue<p_int_str, vector<p_int_str>, Compare> pq;

    while(N--)
    {
        cin >> str;
        pq.push(make_pair(str.length(), str));
    }

    string pres = "";
    string prev = "";
    while(!pq.empty())
    {
        pres = pq.top().second;
        
        if(prev != pres)
            cout << pres << "\n";

        prev = pres;
        pq.pop();
    }

    return 0;
}