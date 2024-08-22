#include <iostream>
#include <utility>

using namespace std;

long long GCD(long long A, long long B);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    long long gcd, i;
    cin >> A >> B;

    gcd = GCD(A, B);

    for(i = 0; i < gcd; i++)
        cout << 1;
    
    return 0;
}

long long GCD(long long A, long long B)
{
    if(A < B)
        swap(A, B);

    long long mod;
    while(1)
    {
        mod = A % B;
        if(mod == 0)
            return B;
        A = B;
        B = mod;
    }
}