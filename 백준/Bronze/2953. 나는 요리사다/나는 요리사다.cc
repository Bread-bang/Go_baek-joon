#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int who, eachScore, i;
    int maxTotal = 0, eachTotal = 0;

    for(i = 0; i < 5; i++)
    {
        eachTotal = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> eachScore;
            eachTotal += eachScore;
        }
        if(maxTotal < eachTotal)
        {
            who = i;
            maxTotal = eachTotal;
        }
    }

    cout << who + 1 << " " << maxTotal << "\n";

    return 0;
}