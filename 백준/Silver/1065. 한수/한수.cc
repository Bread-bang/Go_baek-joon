#include <iostream>

#define start 100

using namespace std;

int ifArithmeticSequence(int num)
{
    bool is_arithmetic_seq = true;
    bool isFirst = true;
    int previous_diff;
    while(num >= 10)
    {
        int num1 = num % 10;
        int num2 = (num / 10) % 10;
        int current_diff = num2 - num1;

        if(isFirst)
        {
            previous_diff = current_diff;
            isFirst = false;
        }
        else
        {
            if(current_diff != previous_diff)
                is_arithmetic_seq = false;
        }

        num /= 10;
    }

    if(is_arithmetic_seq) return 1;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int arithmetic_seq_cnt = 0;
    if(N > 99)
    {
        arithmetic_seq_cnt = 99;
        int i;
        for(i = start; i <= N; i++)
        {
            arithmetic_seq_cnt += ifArithmeticSequence(i);
        }
    }
    else
    {
        arithmetic_seq_cnt = N;
    }

    cout << arithmetic_seq_cnt << "\n";

    return 0;
}