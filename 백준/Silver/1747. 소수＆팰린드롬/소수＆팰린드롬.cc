#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int * A = new int[10000001];
    for(int i = 0; i < 10000001; i++)
        A[i] = i;
    A[1] = 0;

    for(int i = 2; i <= sqrt(10000001); i++)
    {
        if(A[i] == 0)
            continue;
        
        for(int j = i * i; j < 10000001; j += i)
            A[j] = 0;
    }

    for(int i = N; i < 10000001; i++)
    {
        if(A[i] != 0)
        {
            string primeNum = to_string(A[i]); 

            int left = 0;
            int right = primeNum.length() - 1; 
            bool isPalindrome = true;

            while(left < right)
            {
                if(primeNum[left++] != primeNum[right--])
                {
                    isPalindrome = false;
                    break;
                }
            }
            if(isPalindrome)
            {
                cout << A[i] << "\n";
                break;
            }
        }
    }

    return 0;
}