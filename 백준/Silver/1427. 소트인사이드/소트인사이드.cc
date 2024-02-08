#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    priority_queue<char, vector<char>> pq;

    string input;
    cin >> input;

    for(int i = 0; i < input.size(); i++)
        pq.emplace(input[i]);

    while(!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }

    return 0;
}