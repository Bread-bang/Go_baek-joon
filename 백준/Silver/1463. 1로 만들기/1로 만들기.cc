#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<pair<int, int> > q;

    q.push(make_pair(N, 0));
    while(!q.empty())
    {
        int cur_node = q.front().first;
        int cur_count = q.front().second;

        q.pop();

        if(cur_node == 1)
        {
            cout << cur_count << "\n";
            break;
        }

        if(cur_node % 3 == 0)
            q.push(make_pair(cur_node / 3, cur_count + 1));
        
        if(cur_node % 2 == 0)
            q.push(make_pair(cur_node / 2, cur_count + 1));
        
        q.push(make_pair(--cur_node, cur_count + 1));
    }


    return 0;
}