#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A = "";
    string B = "";

    cin >> A >> B;

    int A_length = A.length();
    int B_length = B.length();
    int len_diff = 0;

    if(A_length > B_length)
    {
        len_diff = A_length - B_length;
    }
    else
    {
        len_diff = B_length - A_length;
        swap(A, B);
        swap(A_length, B_length);
    }

    for(int i = 0; i < len_diff; i++)
        B = "0" + B;

    int num_zero = A.length() - 1;
    int carry = 0;
    string total = "";
    
    for(int i = A_length - 1; i >= 0; i--)
    {
        int sub_sum = (int)(A[i] - '0') + (int)(B[i] - '0') + carry;
        carry = sub_sum / 10;
        total = to_string(sub_sum % 10) + total;
    }
    
    if (carry != 0)
    {
        total = to_string(carry) + total;
    }

    cout << total << endl;

    return 0;
}
