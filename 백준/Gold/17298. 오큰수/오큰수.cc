#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int num;
    cin >> N;

    stack<int> s;
    vector<int> seq_nums(N, 0);
    vector<int> result(N, 0);

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        seq_nums[i] = num;
    }

    for(int i = 0; i < N; i++)
    {
        s.push(i);

        int next_idx = s.top() + 1;
        if(next_idx == N) 
            break;

        while(!s.empty() && seq_nums[s.top()] < seq_nums[next_idx])
        {
            result[s.top()] = seq_nums[next_idx];
            s.pop();
        }
    }

    for(int i = 0; i < result.size(); i++)
    {
        if(result[i] == 0)
            cout << "-1 ";
        else
            cout << result[i] << " ";
    }

    return 0;
}