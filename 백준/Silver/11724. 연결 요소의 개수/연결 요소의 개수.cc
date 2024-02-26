#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int v)
{
    stack<int> s;
    s.push(v);
    visited[v] = true;

    while(!s.empty())
    {
        int current_node = s.top();
        s.pop();
        
        for(int next_node : graph[current_node])
        {
            if(!visited[next_node])
            {
                visited[next_node] = true;
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1); // 0은 없는 셈 칠거니까
    visited.resize(N + 1);

    int targetNode, linkingNode;
    for(int i = 0; i < M; i++)
    {
        cin >> targetNode >> linkingNode;
        graph[targetNode].push_back(linkingNode);
        graph[linkingNode].push_back(targetNode);
    }

    fill(visited.begin(), visited.end(), false);

    for(int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());
    
    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
            cnt += dfs(i);
    }

    cout << cnt << "\n";

    return 0;
}