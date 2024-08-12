#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    if(N == 1)
    {
        cout << "0\n";
        return 0;
    }

    priority_queue<int, vector<int>, greater<int> > q;

    int num;
    while(N--)
    {
        cin >> num;
        q.push(num);
    }

    int sum;
    int total = 0;
    while(!q.empty())
    {
        sum = 0;
        sum += q.top(); q.pop();
        sum += q.top(); q.pop();

        if(!q.empty())
            q.push(sum);
        total += sum;
    }

    cout << total << "\n";

    return 0;
}
