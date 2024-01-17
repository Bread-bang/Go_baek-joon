#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int i, p_cnt = 0, y_cnt = 0;
    
    for(i = 0; i < s.size(); i++)
    {
        if(s.at(i) == 'p' || s.at(i) == 'P') p_cnt++;
        else if(s.at(i) == 'y' || s.at(i) == 'Y') y_cnt++;
    }
    
    if(p_cnt != y_cnt && (p_cnt != 0 || y_cnt != 0)) answer = false;

    return answer;
}