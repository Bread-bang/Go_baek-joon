#include <iostream>
#include <vector>

using namespace std;

void DFS(int node);

vector<vector<int> > adjacent_list;
vector<bool> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    adjacent_list.resize(N + 1);
    visited.resize(N + 1, false);

    for(int i = 0; i < M; i++)
    {
        int idx, val;
        cin >> idx >> val;

        adjacent_list[idx].push_back(val);
        adjacent_list[val].push_back(idx);
    }

    int count = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            DFS(i);
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}

void DFS(int node)
{
    if(visited[node])
        return ;
    
    visited[node] = true;

    for(int i = 0; i < adjacent_list[node].size(); i++)
    {
        if(!visited[adjacent_list[node][i]])
            DFS(adjacent_list[node][i]);
    }
}