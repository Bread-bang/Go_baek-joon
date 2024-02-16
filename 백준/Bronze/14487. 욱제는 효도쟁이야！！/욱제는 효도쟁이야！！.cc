#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, num, sum = 0;
    cin >> N;
    vector<int> v;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N - 1; i++)
        sum += v[i];
    
    cout << sum;

    return 0;
}