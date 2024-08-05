#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int V);
void BFS(int V);

vector<vector<int> > list;
vector<bool> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    list.resize(N + 1);
    visited.resize(N + 1, false);

    int idx, val;
    for(int i = 1; i <= M; i++)
    {
        cin >> idx >> val;
        list[idx].push_back(val);
        list[val].push_back(idx);
    }

    for(int i = 1; i <= N; i++)
        sort(list[i].begin(), list[i].end());

    DFS(V);
    cout << "\n";

    BFS(V);
    cout << "\n";

    return 0;
}

void DFS(int V)
{
    cout << V << " ";
    
    if(visited[V])
        return ;
    
    visited[V] = true;

    for(int num : list[V])
    {
        if(!visited[num])
            DFS(num);
    }
}

void BFS(int V)
{
    fill(visited.begin(), visited.end(), false);
    queue<int> q;

    q.push(V);
    visited[V] = true;

    while(!q.empty())
    {
        int currentNode = q.front();
        cout << currentNode << " ";
        q.pop();

        for(int num : list[currentNode])
        {
            if(!visited[num])
            {
                q.push(num);
                visited[num] = true;
            }
        }
    }
}