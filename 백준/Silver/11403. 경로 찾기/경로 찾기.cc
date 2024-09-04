#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > list;
vector<bool> visited;

void dfs(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    list.resize(N);
    visited.resize(N, false);

    for(int i = 0; i < N; i++)
    {
        int arrow = 0;
        for(int j = 0; j < N; j++)
        {
            cin >> arrow;
            if(arrow == 1)
                list[i].push_back(j);
        }
    }

    for(int i = 0; i < N; i++)
    {
        dfs(i);
        for(int j = 0; j < N; j++)
            cout << visited[j] << " ";
        cout << "\n";

        visited.assign(N, false);
    }

    return 0;
}

void dfs(int node)
{
    for(auto neighbor : list[node])
    {
        if(!visited[neighbor])
        {
            visited[neighbor] = true;
            dfs(neighbor);
        }
    }
}