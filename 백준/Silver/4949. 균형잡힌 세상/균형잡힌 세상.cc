#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sentence = "";
    stack<char> s;

    while(1)
    {
        getline(cin, sentence);
        if(!sentence.compare("."))
            break;

        for(char ch : sentence)
        {
            switch (ch)
            {
            case '(':
                s.push(ch);
                break;

            case ')':
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else
                    s.push(ch);
                break;

            case '[':
                s.push(ch);
                break;

            case ']':
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else
                    s.push(ch);
                break;
            
            default:
                break;
            }

            if(ch == '.')
                break;
        }

        if(s.empty())
            cout << "yes\n";
        else
        {
            cout << "no\n";

            while(!s.empty())
                s.pop();
        }
    }

    return 0;
}