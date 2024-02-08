#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    deque<int> dq;

    while(N)
    {
        dq.push_front(N--);
    }

    cout << "<";
    int idx = 0;
    while(!dq.empty())
    {
        idx = (idx + K - 1) % dq.size();
        cout << dq[idx];
        dq.erase(dq.begin() + idx);
        if(!dq.empty())
            cout <<", ";
    }
    cout << ">\n";


    return 0;
}