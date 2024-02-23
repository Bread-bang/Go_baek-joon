#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> unit = {500, 100, 50, 10, 5, 1};
    int original = 1000, count = 0;
    int balance, pay;

    cin >> pay;
    balance = original - pay;

    int i = 0;
    while(balance > 0)
    {
        if(balance >= unit[i])
        {
            balance -= unit[i];
            count++;
        }
        else
            i++;
    }

    cout << count << "\n";

    return 0;
}