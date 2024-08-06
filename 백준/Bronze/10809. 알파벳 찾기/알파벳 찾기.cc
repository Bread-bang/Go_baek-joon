#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<char> v_alphabet;
    vector<int> v_alphaIdx(26, -1);
    vector<bool> v_alpha_isFirst(26, false);

    for(char c = 'a'; c <= 'z'; c++)
        v_alphabet.push_back(c);

    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 0; j < v_alphabet.size(); j++)
        {
            if(str[i] == v_alphabet[j])
            {
                if(!v_alpha_isFirst[j])
                {
                    v_alphaIdx[j] = i;
                    v_alpha_isFirst[j] = true;
                }
            }
        }        
    }

    for(int num : v_alphaIdx)
        cout << num << " ";
    cout << endl;

    return 0;
}