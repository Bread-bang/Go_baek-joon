#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    long long count = 0;
    vector<long long> arr_Sum(N + 1, 0);
    vector<long long> arr_R(M + 1, 0);

    int temp;
    for(int i = 1; i <= N; i++)
    {
        cin >> temp;
        arr_Sum[i] = arr_Sum[i - 1] + temp;
    }

    // 누적 합 배열의 원소를 순회하면서 % M을 수행
    // 결과는 arr_R의 인덱스가 됨.
    // 결과가 나올 때 마다 해당 인덱스의 원소는 +1 해야 함.
    int reminder;
    for(int i = 1; i <= N; i++)
    {
        reminder = arr_Sum[i] % M;
        if(reminder == 0)
            count++;
        arr_R[reminder]++;
    }

    // Combination
    for(int i = 0; i < M; i++)
        count += arr_R[i] * (arr_R[i] - 1) / 2;

    cout << count << "\n";

    return 0;
}