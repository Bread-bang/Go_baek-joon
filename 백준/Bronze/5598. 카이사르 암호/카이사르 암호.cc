#include <iostream>

using namespace std;

int main(){

    string input;
    cin >> input;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] <= 67)
        {
            cout << (char)(input[i] + 23);
        }
        else
            cout << (char)(input[i] - 3);
    }
    cout << "\n";

    return 0;
}