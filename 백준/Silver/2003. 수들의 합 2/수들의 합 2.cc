#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    int start_idx = 0, end_idx = 0;
    int count = 0;
    int sum = arr[0];

    while(start_idx < N)
    {
        if(sum > M)
        {
            if(start_idx == end_idx)
            {
                sum -= arr[start_idx];
                start_idx++;
                end_idx++;
                sum += arr[start_idx];
            }
            sum -= arr[start_idx++];
        }   
        else if(sum == M)
        {
            count++;
            sum -= arr[start_idx++];
        } 
        else
        {
            if(end_idx == N - 1)
                break;
            sum += arr[++end_idx];
        }
    }

    cout << count << "\n";

    return 0;
}