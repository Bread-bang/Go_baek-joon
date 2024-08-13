#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 1;
    int startInteger = 666;
    string strInteger = "";
    string targetString = "666";
    while(1)
    {
        strInteger = to_string(startInteger);

        size_t pos = strInteger.find(targetString);
        if(pos != string::npos)
        {
            if(count == N)
            {
                cout << strInteger << "\n";
                break;
            }

            count++; 
        }
        
        startInteger++;
    }

    return 0;
}