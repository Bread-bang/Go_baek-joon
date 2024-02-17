#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, original_num;
    cin >> N;

    while(N--)
    {
        int reverse_num = 0, sum = 0;
        bool judgement = true;
        cin >> original_num;
        int temp_num = original_num;
        string s_num = to_string(temp_num);

        for(int i = s_num.size() - 1; i >= 0; i--)
        {
            reverse_num += (temp_num % 10) * pow(10, i);
            temp_num /= 10;
        }

        sum = original_num + reverse_num;
        string s_sum = to_string(sum);

        for(int i = 0; i < s_sum.size() / 2; i++)
        {
            if(s_sum[i] != s_sum[s_sum.size() - 1 - i])
                judgement = false;
        }

        if(judgement) cout << "YES\n";
        else cout << "NO\n";
    }

    

    return 0;
}