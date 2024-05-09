#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, Q_count;
    int start, end;
    int target_arr[100001];
    int prefix_sum[100001];
    int answer;

    cin >> N >> Q_count;

    for(int i = 1; i <= N; i++)
    {
        cin >> target_arr[i];
        if(i == 1)
            prefix_sum[i] = target_arr[i];
        else
            prefix_sum[i] = prefix_sum[i - 1] + target_arr[i];
    }
    
    for(int x = 0; x < Q_count; x++)
    {
        cin >> start >> end;
        cout << prefix_sum[end] - prefix_sum[start - 1] << "\n";
    }

    return 0;
}