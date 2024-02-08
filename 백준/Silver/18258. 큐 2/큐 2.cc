#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int * queue = new int[N];
    int front_position = 0; // out 하는 곳
    int rear_position = 0;  // in 하는 곳  
    char cmd[15];
    while(N--)
    {
        int num;
        cin >> cmd;
        if(!strcmp(cmd, "push"))
        {
            cin >> num;
            queue[rear_position++] = num;
        }
        else if(!strcmp(cmd, "pop"))
        {
            if(front_position == rear_position)
                cout << "-1\n";
            else
                cout << queue[front_position++] << "\n";
        }
        else if(!strcmp(cmd, "size"))
        {
            cout << rear_position - front_position << "\n";
        }
        else if(!strcmp(cmd, "empty"))
        {
            if(front_position == rear_position)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(!strcmp(cmd, "front"))
        {
            if(queue[front_position] == 0)
                cout << "-1\n";
            else
                cout << queue[front_position] << "\n";
        }
        else if(!strcmp(cmd, "back"))
        {
            if(front_position == rear_position)
                cout << "-1\n";
            else
                cout << queue[rear_position - 1] << "\n";
        }
    }

    return 0;
}