#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<pair<int, int> > arr;

    cin >> N;

    int num = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(make_pair(num, i));
    }

    sort(arr.begin(), arr.end());

    int max = arr[0].second;
    int diff_idx = 0;
    for(int i = 1; i < N; i++)
    {
        diff_idx = arr[i].second - i;
        max = (max > diff_idx) ? max : diff_idx;
    }

    cout << max + 1 << "\n";

    return 0;
}