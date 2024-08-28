#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, string> m_int;
    map<string, int> m_str;

    int N, M;
    cin >> N >> M;
    cin.ignore();

    for(int i = 1; i <= N; i++)
    {
        string str;
        getline(cin, str);

        m_int[i] = str;
        m_str[str] = i;
    } 

    while(M--)
    {
        string question;
        getline(cin, question);

        if(question[0] >= 65 && question[0] <= 90)
        {
            if(m_str.find(question) != m_str.end())
            {
                cout << m_str[question] << "\n";
            }
        }
        else
        {
            int num = stoi(question);
            if(m_int.find(num) != m_int.end())
            {
                cout << m_int[num] << "\n";
            }
        }
    }

    return 0;
}