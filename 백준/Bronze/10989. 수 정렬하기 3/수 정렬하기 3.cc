#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(10001);

    int num = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        arr[num]++;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            for(int j = 0; j < arr[i]; j++)
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;

    return 0;
}