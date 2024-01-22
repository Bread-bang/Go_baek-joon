#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];

    for(int i = 0; i < N; i++)
        cin >> B[i];
    
    /**
     * @brief 
     * B의 가장 큰 원소 * A의 가장 작은 원소
     * 1. A 오름차순 sorting
     * 2. B의 가장 큰 원소 찾기
     * 3. SUM = A * B 
     * 4. B의 max element pop
     */

    int sum = 0, max_idx;
    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++)
    {
        max_idx = max_element(B.begin(), B.end()) - B.begin();
        sum += (A[i] * B[max_idx]);
        B[max_idx] = -1;
    }

    cout << sum << endl;

    return 0;
}