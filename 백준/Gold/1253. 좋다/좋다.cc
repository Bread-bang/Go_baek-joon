#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int num = 0;
    int i = 0, j = 0;
    int count = 0;

    vector<int> arr;

    cin >> N;

    j = N - 1;

    for(int t = 0; t < N; t++)
    {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    for(int t = 0; t < N; t++)
    {
        while(i < j)
        {
            if(arr[i] + arr[j] == arr[t])
            {
                if(i != t && j != t)
                {
                    count++;
                    break;
                }
                else if(i == t)
                    i++;
                else if(j == t)
                    j--;
            }
            else if(arr[i] + arr[j] > arr[t])
            {
                j--;
            }
            else if(arr[i] + arr[j] < arr[t])
            {
                i++;
            }
        }

        i = 0;
        j = N - 1;
    }

    cout << count << "\n";

    return 0;
}