#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

using namespace std;

void DFS(int node);

vector<long long> weight;
vector<bool> visited;
vector<vector<tuple<int, int, int> > > A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    weight.resize(N);
    visited.resize(N, false);
    A.resize(N);

    long long lcm = 1;
    for(int i = 0; i < N - 1; i++)
    {
        int cur_node, tgt_node;
        int p, q;

        cin >> cur_node >> tgt_node >> p >> q;
        A[cur_node].push_back(make_tuple(tgt_node, p, q));
        A[tgt_node].push_back(make_tuple(cur_node, q, p));

        lcm *= p * q / gcd(p, q);
    }

    weight[0] = lcm;

    // DFS 탐색으로 비율을 이용하여 가중치 계산
    DFS(0);

    // 가중치 끼리의 최대공약수를 계산
    long long all_gcd = lcm;
    for(int i = 1; i < N; i++)
        all_gcd = gcd(weight[i], all_gcd);

    for(int i = 0; i < N; i++)
        cout << weight[i] / all_gcd << " ";
    cout << "\n";

    return 0;
}

void DFS(int node)
{
    if(visited[node])
        return ;
    
    visited[node] = true;

    long long cur_weight = weight[node];

    for(auto& v : A[node])
    {
        int adj_node = get<0>(v);
        if(!visited[adj_node])
        {
            weight[adj_node] = cur_weight * get<2>(v) / get<1>(v);
            DFS(adj_node);
        }
    } 
}
