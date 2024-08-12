#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int> > arr;

    int num1, num2;
    while(N--)
    {
        cin >> num1 >> num2;
        arr.push_back(make_pair(num1, num2));
    }

    sort(arr.begin(), arr.end(), compare);

    for(auto& each : arr)
        cout << each.first << " " << each.second << "\n";

    return 0;
}