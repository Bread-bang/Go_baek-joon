#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare 
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0, x = 0;
    priority_queue<int, vector<int>, Compare> pq;
    
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        if(x == 0)
        {
            if(pq.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}