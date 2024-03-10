#include <iostream>

using namespace std;

int GCD_calculate(int dividend, int divisor)
{
    int reminder;
    while(1)
    {
        reminder = dividend % divisor;
        if(reminder == 0)
            break;
        dividend = divisor;
        divisor = reminder;
    }
    int GCD = divisor;
    return GCD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while(N--)
    {
        int A, B;
        cin >> A >> B;

        // 큰 수가 A로 되게끔
        if(A < B)
        {
            int temp;
            temp = A;
            A = B;
            B = temp;
        }
        int GCD = GCD_calculate(A, B);
        

        // LCM = 두 자연수의 곱 / GCD
        int LCM = A * B / GCD;

        cout << LCM << "\n";
    }

    return 0;
}