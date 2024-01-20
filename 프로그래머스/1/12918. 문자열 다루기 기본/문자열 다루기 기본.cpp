#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    size_t sz;
    
    if(!(s.size() == 4 || s.size() == 6))
    {
        answer = false;
        return answer;        
    }
    else
    {
        for(int i = 0; i < s.size(); i++)
        {
            if((int)s[i] < 47 || (int)s[i] > 57)
            {
                answer = false;
                break;                
            }
        }
    }    
    
    return answer;
}