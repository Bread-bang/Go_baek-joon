#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while(N--)
    {
        int k, passenger;
        cin >> k;
        
        passenger = pow(2, k) - 1;

        cout << passenger << "\n";
    }
    
    return 0;
}