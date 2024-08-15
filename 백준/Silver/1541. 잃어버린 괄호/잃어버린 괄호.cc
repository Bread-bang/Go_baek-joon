#include <iostream>
#include <string>

using namespace std;

int main()
{
    int total = 0;
    string temp = "";
    bool isNegative = false;
    string str;
    cin >> str;

    for(auto ch : str)
    {
        if(ch == '-' || ch == '+')
        {
            if(!isNegative)
                total += stoi(temp);
            else
                total -= stoi(temp);

            if(ch == '-')
                isNegative = true;

            temp = "";
        }
        else
            temp += ch;
    }
    if(!isNegative)
        total += stoi(temp);
    else
        total -= stoi(temp);

    cout << total << "\n";

    return 0;
}