#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num = 0, next_num = 1;
    string result = "";
    stack<int> s;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;

        if(s.empty())
        {
            int j;
            for(j = next_num; j <= num; j++)
            {
                s.push(j);
                result.append("+");
            }
            next_num = j;

            s.pop();
            result.append("-");
        }
        else
        {
            if(s.top() == num)
            {
                s.pop();
                result.append("-");
            }
            else if(s.top() > num)
            {
                cout << "NO\n";
                return 0;
            }
            else
            {
                int j;
                for(j = next_num; j <= num; j++)
                {
                    s.push(j);
                    result.append("+");
                }
                next_num = j;

                s.pop();
                result.append("-");
            }
        }
    }

    for(auto ch : result)
        cout << ch << "\n";

    return 0;
}