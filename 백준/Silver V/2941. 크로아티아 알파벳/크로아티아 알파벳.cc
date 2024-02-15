#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    
    int cnt = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == 'c' && ((input[i + 1] == '=') || (input[i + 1] == '-')))
        {
            cnt++;
            i++;
        }
        else if(input[i] == 'd')
        {
            if(input[i + 1] == 'z' && input[i + 2] == '=')
            {
                cnt++;
                i += 2;    
            }
            else if(input[i + 1] == '-')
            {
                cnt++;
                i++;
            }
            else
            {
                cnt++;
            }
        }
        else if(input[i] == 'l' && (input[i + 1] == 'j'))
        {
            cnt++;
            i++;
        }
        else if(input[i] == 'n' && (input[i + 1] == 'j'))
        {
            cnt++;
            i++;
        }
        else if(((input[i] == 's') || (input[i] == 'z')) && input[i + 1] == '=')
        {
            cnt++;
            i++;
        }
        else
        {
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}