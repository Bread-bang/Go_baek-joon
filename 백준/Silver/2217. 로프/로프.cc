#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int each_rope;
    vector<int> list_rope;
    for(int i = N; i > 0; i--)
    {
        cin >> each_rope;
        list_rope.push_back(each_rope);
    }

    sort(list_rope.begin(), list_rope.end());

    int max = list_rope[0] * N;
    int idx = 1;
    for(int i = N - 1; i > 0; i--)
    {
        int next_candidate = list_rope[idx] * i;
        max = max > next_candidate ? max : next_candidate;
        idx++;
    }

    cout << max << endl;
    
    return 0;
}