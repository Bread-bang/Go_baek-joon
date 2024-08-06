#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count = 0;
    bool isStarted = false;

    while(1)
    {
        char c;
        cin.get(c);

        if(c == '\n')
        {
            if(isStarted)
                count++;
            break;
        }

        if(!isStarted && c == ' ') 
        {
            continue;
        }
        else if(isalpha(c))
        {
            isStarted = true;
        }
        else if(isStarted && c == ' ')
        {
            isStarted = false;
            count++;
        }
    }

    cout << count << "\n";
    
    return 0;
}