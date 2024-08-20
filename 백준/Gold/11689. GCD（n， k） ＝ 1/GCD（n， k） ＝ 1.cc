#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    long long result = N;

    for(int i = 2; i <= sqrt(N); i++)
    {
        // i가 N의 소인수 이면
        if(N % i == 0)
        {
            result = result - result / i;

            // i가 n제곱 일 경우 삭제
            while(N % i == 0)
                N /= i;
        }
    }
    
    // 소인수가 남아있을 경우
    if(N > 1)
        result = result - result / N;

    cout << result << "\n";

    return 0;
}