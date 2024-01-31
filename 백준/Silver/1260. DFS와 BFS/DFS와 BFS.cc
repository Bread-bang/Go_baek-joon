#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v)
{
    fill(visited.begin(), visited.end(), false);
    stack<int> s;
    s.emplace(v);
    cout << v << " ";
    visited[v] = true;

    while(!s.empty())
    {
        int current_node = s.top();
        s.pop();

        for(int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];

            if(visited[next_node] == false)
            {
                cout << next_node << " ";
                visited[next_node] = true;
                s.emplace(current_node);
                s.emplace(next_node);
                break;
            }
        }
    }
    cout << "\n";
}

void bfs(int v)
{
    fill(visited.begin(), visited.end(), false);
    queue<int> q;
    q.emplace(v);
    visited[v] = true;

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";

        for(int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];
            if(visited[next_node] == false)
            {
                q.emplace(next_node);
                visited[next_node] = true;
            }
        }
    }
    cout << "\n";
}

int main() {

    cin >> N >> M >> V;
    graph.resize(N + 1);
    visited.resize(N + 1);

    int A, B;
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }

    for(int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);
    bfs(V);

    return 0;
}