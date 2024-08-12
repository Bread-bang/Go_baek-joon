#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    int total = 0;
    vector<int> arr(N);

    cin >> N >> K;

    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    for(int i = N - 1; i >= 0; i--)
    {
        if(arr[i] > K)
            continue;
        else
        {
            int quotient = (K / arr[i]);
            K -= (quotient * arr[i]);
            total += quotient;
        }

        if(K == 0)
            break;
    }
    
    cout << total << "\n";

    return 0;
}