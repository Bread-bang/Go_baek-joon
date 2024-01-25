#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // C++의 표준 스트림(iostream)과 C의 표준 스트림(stdio) 간의 동기화를 비활성화함.
    cin.tie(0);

/**
 * @brief 
 *  정수 N개 만큼 아래의 과정을 반복한다.
 *      입력을 하나 받는다.
 *      priority_queue(original)에 push한다.
 *      temp queue에 original queue의 포인터 주소를 대입한다.
 *           0 ~ (size / 2) + 1 번 반복하여 top을 확인하고 pop을 한다. 이 때 출력은 마지막 반복 때에만 한다.
 */

    // priority_queue<int> original_pq;
    // priority_queue<int> temp_pq;

    // int N, num;
    // cin >> N;

    // for(int i = 0; i < N; i++)
    // {
    //     cin >> num;
    //     original_pq.push(num);
    //     temp_pq = original_pq;

    //     for(int j = 0; j < (original_pq.size() / 2 + 1); j++)
    //     {
    //             if(j == original_pq.size() / 2) cout << temp_pq.top() << "\n";
    //         temp_pq.pop();
    //     }
    // }

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    int N, num;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;

        if(maxHeap.empty())
        {
            maxHeap.push(num);
            cout << maxHeap.top() << endl;
            continue;
        }
        
        if(maxHeap.top() < num)
            minHeap.push(num);
        else
            maxHeap.push(num);

        if(maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        

        cout << maxHeap.top() << "\n";

    }

    return 0;
}