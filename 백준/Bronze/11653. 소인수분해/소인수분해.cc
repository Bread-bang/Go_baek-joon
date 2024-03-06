#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int num = 2;
    while(N != 1)
    {
        if(N % num == 0)
        {
            cout << num << "\n";
            N /= num;
        }
        else
            num++;
    }

    return 0;
}