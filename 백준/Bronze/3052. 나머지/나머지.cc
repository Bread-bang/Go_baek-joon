#include <iostream>
#include <map>

using namespace std;

int main() {

    int input_num, cnt = 0;
    map<int, int> m;
    
    for(int i = 0; i < 10; i++)
    {
        cin >> input_num;
        int key = input_num % 42;

        if(m.find(key) == m.end())
        {
            m[key] = 0;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}