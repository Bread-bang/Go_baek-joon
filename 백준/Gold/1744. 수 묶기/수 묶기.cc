#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> whole;
    vector<int> negative;
    vector<int> zeroToOne;
    vector<int> positive;

    int N;
    cin >> N;

    while(N--)
    {
        int num;
        cin >> num;
        whole.push_back(num);
    }

    sort(whole.begin(), whole.end());

    bool existZero = false;
    for(auto each : whole)
    {
        if(each < 0)
            negative.push_back(each);
        else if(each == 0)
        {
            zeroToOne.push_back(each);
            existZero = true;
        }
        else if(each == 1)
            zeroToOne.push_back(each);
        else
            positive.push_back(each);
    }

    sort(negative.begin(), negative.end());
    sort(positive.begin(), positive.end(), greater<int>());

    int total = 0;
    if(negative.size() % 2 == 0)
    {
        for(int i = 0; i < negative.size(); i += 2)
            total += (negative[i] * negative[i + 1]);
    }
    else
    {
        for(int i = 0; i < negative.size() - 1; i += 2)
            total += (negative[i] * negative[i + 1]);

        if(!existZero)
            zeroToOne.push_back(negative[negative.size() - 1]);
    }

    for(int num : zeroToOne)
        total += num;
    
    if(positive.size() % 2 == 0)
    {
        for(int i = 0; i < positive.size(); i += 2)
            total += (positive[i] * positive[i + 1]);
    }
    else
    {
        for(int i = 0; i < positive.size() - 1; i += 2)
            total += (positive[i] * positive[i + 1]);
        total += positive[positive.size() - 1];
    }

    cout << total << "\n";

    return 0;
}