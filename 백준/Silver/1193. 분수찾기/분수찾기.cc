#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, diag_num = 0, element_cnt = 0;
    cin >> input;

    while(input > element_cnt)
    {
        diag_num++;
        element_cnt += diag_num;
    }

    int offset = element_cnt - input;

    int numerator, denominator;
    if(diag_num % 2 == 0)
    {
        numerator = diag_num - offset;
        denominator = offset + 1;
    }
    else
    {
        numerator = offset + 1;
        denominator = diag_num - offset;
    }
    

    cout << numerator << "/" << denominator << "\n";

    return 0;
}