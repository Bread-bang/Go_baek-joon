#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binarySearch(int num, vector<int>& targetArr);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> targetArr(N);
    for(int i = 0; i < N; i++)
        cin >> targetArr[i];

    sort(targetArr.begin(), targetArr.end());
    
    int M;
    cin >> M;
    vector<int> searchArr(M);
    for(int i = 0; i < M; i++)
        cin >> searchArr[i];
    
    for(int num : searchArr)
        binarySearch(num, targetArr);

    return 0;
}

void binarySearch(int num, vector<int>& targetArr)
{
    int left = 0;
    int right = targetArr.size() - 1;
    bool isFound = false;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(targetArr[mid] > num)
        {
            right = mid - 1;
        }
        else if (targetArr[mid] < num)
        {
            left = mid + 1;
        }
        else 
        {
            isFound = true;
            break;
        } 
    }

    if(isFound)
        cout << "1\n";
    else
        cout << "0\n";
}