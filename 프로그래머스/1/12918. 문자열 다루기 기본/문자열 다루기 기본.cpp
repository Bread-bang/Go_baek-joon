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
        for(char temp_ch : s)
        {
            if(!(isdigit(temp_ch)))
            {
                answer = false;
                break;
            }
        }
    }    
    
    return answer;
}