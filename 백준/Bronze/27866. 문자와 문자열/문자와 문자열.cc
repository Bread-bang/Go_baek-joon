#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    int i;

    cin >> word >> i;

    cout << word[i - 1] << "\n";

    return 0;
}