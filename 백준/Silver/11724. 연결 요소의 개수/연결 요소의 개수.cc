#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > adjacent_list;
vector<bool> visited;

void DFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    adjacent_list.resize(N + 1);
    visited.resize(N + 1, false);

    int idx, val;
    for(int i = 0; i < M; i++)
    {
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
    stack<int> s;
    s.push(node);
    visited[node] = true;
    
    while(!s.empty())
    {
        int currentNode = s.top();
        s.pop();
        for(int i = 0; i < adjacent_list[currentNode].size(); i++)
        {
            if(!visited[adjacent_list[currentNode][i]])
            {
                s.push(adjacent_list[currentNode][i]);
                visited[adjacent_list[currentNode][i]] = true;
            }
        }
    }
}