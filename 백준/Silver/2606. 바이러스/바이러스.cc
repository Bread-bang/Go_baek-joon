#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int result = 0;

void dfs(int start)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while(!s.empty())
    {
        int current_node = s.top();
        s.pop();

        for(int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];

            if(visited[next_node] == false)
            {
                visited[next_node] = true;
                result++;
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }

    }
}

int main(){

    int N, E;
    cin >> N >> E;

    graph.resize(N + 1);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);

    for(int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }

    dfs(1);
    cout << result << "\n";
    return 0;
}