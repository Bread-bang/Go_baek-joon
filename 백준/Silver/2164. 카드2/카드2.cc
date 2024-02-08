#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque<int> dq;

    while(N)
    {
        dq.push_front(N--);
    }

    while(dq.size() != 1)
    {
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    cout << dq.front() << endl;
    return 0;
}