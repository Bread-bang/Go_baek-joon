#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string inputString;
    getline(cin, inputString);

    int newLine = 1;
    for(int i = 0; i < inputString.size();i++)
    {
        cout << inputString[i];
        if(newLine == 10)
        {
            cout << "\n";
            newLine = 1;
            continue;
        }
        newLine++;
        
    }

    return 0;
}