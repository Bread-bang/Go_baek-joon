#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int * arr = new int(N);

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 1; i < N; i++)
    {
        int j = i;
        while(arr[j - 1] >= arr[j] && j > 0)
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    int sub_sum = 0, tot_sum = 0;
    for(int i = 0; i < N; i++)
    {
        sub_sum += arr[i];
        tot_sum += sub_sum;
    }

    cout << tot_sum << "\n";

    return 0;
}