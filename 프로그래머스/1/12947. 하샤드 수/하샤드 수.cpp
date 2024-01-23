#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = x;
    int sum = 0;
    
    while(temp > 0)
    {
        sum += (temp % 10);
        temp /= 10;
    }
    
    answer = (x % sum == 0) ? true : false;
        
    return answer;
}