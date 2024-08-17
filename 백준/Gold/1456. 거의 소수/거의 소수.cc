#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long Min, Max;
    cin >> Min >> Max;
    long * A = new long[10000001];

    for(int i = 2; i < 10000001; i++)
        A[i] = i;

    for(long long i = 2; i <= sqrt(10000001); i++)
    {
        if(A[i] == 0)
            continue;

        for(int j = i * i; j <= 10000001; j += i)
            A[j] = 0;
    }

    int nearlyPrimeCount = 0;
    for(long long i = 2; i <= 10000001; i++)
    {
        if(A[i] != 0)
        {
            long temp = A[i];

            while((double)A[i] <= (double)Max / (double)temp)
            {
                if((double)A[i] >= (double)Min / (double)temp)
                {
                    nearlyPrimeCount++;
                }
                temp *= A[i];
            }
        }
    }
    cout << nearlyPrimeCount << "\n";

    return 0;
}