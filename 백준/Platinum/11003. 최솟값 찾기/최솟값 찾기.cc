#include <iostream>
#include <utility>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0, L = 0;
    cin >> N >> L;

    deque<Node> dq;
    deque<Node>::iterator iter;

    int num = 0;
    int front_idx = 0;
    int idx_diff = 0;

    for(int i = 1; i <= N; i++)
    {
        cin >> num;
        dq.push_back(make_pair(i, num));

        // 값 비교
        while(dq.size() > 1 && dq[dq.size() - 2].second > dq.back().second)
        {
            front_idx = dq.size() - 2;
            iter = dq.begin() + front_idx;
            dq.erase(iter);
        }

        // 인덱스와 윈도우 크기 비교
        idx_diff = dq.back().first - dq.front().first + 1;
        if(idx_diff > L)
            dq.pop_front();

        cout << dq.front().second << " ";
    }
    cout << "\n";

    return 0;
}