#include <iostream>
#include <string>

int main(){
    std::string str_num1, str_num2, bigger;

    std::cin >> str_num1 >> str_num2;

    int i;
    int num1_size = str_num1.length();

    for(i = num1_size - 1; i >= 0; i--)
    {
        if (str_num1[i] > str_num2[i])
        {
            bigger = str_num1;
            break;
        }
        else if (str_num1[i] < str_num2[i])
        {
            bigger = str_num2;
            break;
        }
    }

    int firstIdx = bigger.find_first_of(bigger.front());
    int lastIdx = bigger.find_last_of(bigger.back());

    for(i = lastIdx; i >= firstIdx; i--)
        std::cout << bigger[i];

    return 0;
}