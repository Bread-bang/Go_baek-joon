#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char input[15];

    int N, num;
    cin >> N;
    int * stack = new int[N];
    int idx = 0;
    while(N--)
    {
        cin >> input;
        if(!strcmp(input, "push"))
        {
            cin >> num;
            stack[idx++] = num;
        }
        else if(!strcmp(input, "pop"))
        {
            if(idx == 0)
                cout << "-1\n";
            else
            {
                cout << stack[idx - 1] << "\n";
                stack[idx--] = -1;  
            }
        }
        else if(!strcmp(input, "size"))
        {
            cout << idx << "\n";
        }
        else if(!strcmp(input, "empty"))
        {
            if(idx == 0)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(!strcmp(input, "top"))
        {
            if(idx == 0)
                cout << "-1\n";
            else
                cout << stack[idx - 1] << "\n";
        }
    }

    return 0;
}