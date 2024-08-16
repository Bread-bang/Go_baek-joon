#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> list(M + 1);

    for(int i = 2; i <= M; i++)
    {
        list[i] = i;
    }

    for(int i = 2; i <= sqrt(M); i++)
    {
        if(list[i] == 0)
            continue;
        
        for(int j = i + i; j <= M; j += i)
            list[j] = 0;
    }

    for(int i = N; i <= M; i++)
    {
        if(list[i] != 0)
            cout << list[i] << "\n";
    }


    return 0;
}