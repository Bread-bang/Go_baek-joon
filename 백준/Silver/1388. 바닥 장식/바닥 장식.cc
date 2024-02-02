#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int cnt;
vector<vector<char>> graph;
vector<vector<bool>> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    graph.resize(N);
    visited.resize(N);

    char input;
    for(int i = 0; i < N; i++)
    {
        graph[i].reserve(M);
        visited[i] = vector<bool>(M, false);
        for(int j = 0; j < M; j++)
        {
            cin >> input;
            graph[i].emplace_back(input);
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(visited[i][j]) continue;
            cnt++;
            visited[i][j] = true;
            if(graph[i][j] == '-')
            {
                for(int k = j + 1; k < M; k++)
                {
                    if(graph[i][k] == '|')
                        break;
                    visited[i][k] = true;
                }
            }
            else if(graph[i][j] == '|')
            {
                for(int k = i + 1; k < N; k++)
                {
                    if(graph[k][j] == '-')
                        break;
                    visited[k][j] = true;
                }
            }
        }
    }

    cout << cnt;
    return 0;
}