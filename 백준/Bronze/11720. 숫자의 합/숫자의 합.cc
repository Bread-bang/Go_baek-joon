#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    string numbers;
    int sum = 0;

    cin >> N >> numbers;

    for(char c : numbers)
    {
        sum += c - '0';
    }

    cout << sum << "\n";

    return 0;
}