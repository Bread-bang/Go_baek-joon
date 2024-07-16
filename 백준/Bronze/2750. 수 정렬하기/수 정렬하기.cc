#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int * arr = new int[N]();

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }

    for(int i = 0; i < N; i++)
        cout << arr[i] << endl;

    return 0;
}