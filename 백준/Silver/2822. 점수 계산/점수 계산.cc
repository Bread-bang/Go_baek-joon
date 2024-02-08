#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main(){

    int score;
    vector<pair<int, int> > v_info;
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 1; i < 9; i++)
    {
        cin >> score;
        v_info.push_back(make_pair(i, score));
    }

    sort(v_info.begin(), v_info.end(), compare);

    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum += v_info[i].second;
        pq.emplace(v_info[i].first);
    }

    cout << sum << "\n";
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    return 0;
}