#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int num);

int fibo_arr[41] = {0, 1, };

int main()
{
    int N;
    cin >> N;

    int num = 0;
    while(N--)
    {
        cin >> num;
        if(num == 0)
            cout << 1 << " " << 0 << "\n";
        else
            cout << fibonacci(num - 1) << " " << fibonacci(num) << "\n";
    }

    return 0;
}

int fibonacci(int num)
{
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else if(fibo_arr[num] == 0)
        fibo_arr[num] = fibonacci(num - 1) + fibonacci(num - 2);
    return fibo_arr[num];
}