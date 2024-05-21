#include <iostream>

using namespace std;

int main () 
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    int count = 1; // 자기 자신
    cin >> N;

    int start_idx = 1, end_idx = 1;
    int sum = 1;
    while(end_idx != N)
    {
        if(sum < N)
        {
            end_idx++;
            sum += end_idx;
        }
        else if(sum == N)
        {
            count++;
            end_idx++;
            sum += end_idx;
        }
        else if(sum > N)
        {
            sum -= start_idx;
            start_idx++;
        }
    }

    cout << count << "\n";

    return 0;
}