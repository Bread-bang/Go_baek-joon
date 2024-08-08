#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int left = 1;
    int right = K;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        int minCount = 0;
        for(int i = 1; i <= N; i++)
            minCount += min((mid / i), N);
        
        if(minCount < K)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << left << "\n";

    return 0;
}