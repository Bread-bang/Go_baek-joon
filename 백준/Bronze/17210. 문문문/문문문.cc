#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int toggle;
    cin >> toggle;

    if(N >= 6)
    {
        cout << "Love is open door\n";
        return 0;
    }

    for(int i = 0; i < N - 1; i++)
    {
        toggle = (toggle == 0) ? 1 : 0; 
        cout << toggle << "\n";
    }

    return 0;
}