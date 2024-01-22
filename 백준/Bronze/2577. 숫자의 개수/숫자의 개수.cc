#include <iostream>
#include <vector>
#include <map>

using namespace std;

int num1, num2, num3;

int main()
{
    cin >> num1;
    cin >> num2;
    cin >> num3;
    
    map<char, int> m = {{'0', 0}, {'1', 0}, {'2', 0}, {'3', 0}, {'4', 0}, {'5', 0}, {'6', 0}, {'7', 0}, {'8', 0}, {'9', 0}};
    string mul_result = to_string(num1 * num2 * num3);
    
    for(int i = 0; i < mul_result.size(); i++)
    {
        m[mul_result[i]]++;
    }

    auto it = m.begin();
    while(it != m.end())
    {
        cout << it->second <<endl;
        ++it;
    }
    return 0;
}