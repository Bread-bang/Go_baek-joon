#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void BFS(int& nodeIdx);

vector<vector<pair<int, int> > > list;
vector<bool> visited;
vector<int> v_distance;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    list.resize(V + 1);
    visited.resize(V + 1, false);
    v_distance.resize(V + 1);

    int j = 0;
    for(int i = 1; i <= V; i++)
    {
        int curNode;
        cin >> curNode;
        while(1)
        {
            int targetNode, distance;
            cin >> targetNode;
            if(targetNode == -1)
                break;
            
            cin >> distance;
            list[curNode].push_back(make_pair(targetNode, distance));
        }
    }

    int nodeIdx;
    for(int i = 1; i <= V; i++)
    {
        if(list[i].size() > 0)
        {
            nodeIdx = i;
            break;
        }
    }

    BFS(nodeIdx);
    int maxDistance = 0;
    for(int i = 1; i <= V; i++)
    {
        if(maxDistance < v_distance[i])
        {
            maxDistance = v_distance[i];
            nodeIdx = i;
        }
    }

    BFS(nodeIdx);
    auto maxDistIter = max_element(v_distance.begin(), v_distance.end());
    if(maxDistIter != v_distance.end())
        cout << *maxDistIter << "\n";

    return 0;
}

void BFS(int& nodeIdx)
{
    fill(visited.begin(), visited.end(), false);
    fill(v_distance.begin(), v_distance.end(), 0);

    queue<int> q;
    q.push(nodeIdx);
    visited[nodeIdx] = true;

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for(pair<int, int> p : list[currentNode])
        {
            int targetNode = p.first;
            int distance = p.second;

            if(!visited[targetNode])
            {
                q.push(targetNode);
                visited[targetNode] = true;
                v_distance[targetNode] = v_distance[currentNode] + distance;
            }   
        }
    }
}