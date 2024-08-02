#include <iostream>
#include <vector>

using namespace std;

bool found = false;
vector<vector<int> > list;
vector<bool> visited;

void DFS(int node, int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    list.resize(N);
    visited.resize(N, false);

    for(int i = 0; i < M; i++)
    {
        int idx, val;
        cin >> idx >> val;

        list[idx].push_back(val);
        list[val].push_back(idx);
    }

    for(int i = 0; i < N; i++)
    {
        DFS(i, 1);
        if(found)
        {
            cout << "1\n";
            return 0;
        }

        found = false;
    }

    cout << "0\n";

    return 0;
}

void DFS(int node, int depth)
{
    if(depth == 5)
    {
        found = true;
        return ;
    }

    if(visited[node])
        return ;
    
    visited[node] = true;

    for(int nextNode : list[node])
    {
        if(!visited[nextNode])
            DFS(nextNode, depth + 1);
    }
    
    visited[node] = false;
}