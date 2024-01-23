#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string temp = to_string(x);
    int sum = 0;
    for(int i = 0; i < temp.size(); i++)
        sum += (int)(temp[i] - '0');

    if(x % sum != 0) answer = false;
        
    return answer;
}