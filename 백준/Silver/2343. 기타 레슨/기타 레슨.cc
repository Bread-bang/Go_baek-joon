#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int binarySearch(int M, int left, int right, vector<int>& lessons);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> lessons(N);

    for(int i = 0; i < N; i++)
        cin >> lessons[i];
    
    int start = *max_element(lessons.begin(), lessons.end());
    int end = accumulate(lessons.begin(), lessons.end(), 0);

    cout << binarySearch(M, start, end, lessons) << "\n";

    return 0;
}

int binarySearch(int M, int left, int right, vector<int>& lessons) 
{
    vector<int> v;
    
    while(left <= right)
    {
        int cnt = 0;
        int mid = (left + right) / 2;
        
        int sum = 0;
        for(int num : lessons) 
        {
            if((sum + num) > mid)
            {
                cnt++;
                sum = 0;
            }

            sum += num;
        }

        if(sum != 0)
            cnt++;

        if(cnt > M)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return left;
}