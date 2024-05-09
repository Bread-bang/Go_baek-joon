#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    int Score;
    int Max = 0;
    int Sum = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> Score;
        Max = (Max > Score) ? Max : Score;
        Sum += Score;
    }
    
    cout << Sum * 100.0 / Max / N << "\n";

    return 0;
}