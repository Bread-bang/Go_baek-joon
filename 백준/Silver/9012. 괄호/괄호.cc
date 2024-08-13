#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    stack<char> s;

    cin >> N;
    cin.ignore();

    string str;
    while(N--)
    {
        getline(cin, str);
        for(char ch : str)
        {
            if(ch == '(')
                s.push(ch);
            else if(ch == ')')
            {
                if(s.empty())
                    s.push(ch);
                else if(s.top() == '(')
                    s.pop();
            }
        }
        if(s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
        
        while(!s.empty())
            s.pop();

    }

    return 0;
}