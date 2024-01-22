#include <iostream>
#include <vector>

using namespace std;

int main() {
    int howMany;
    int available = 0;

    cin >> howMany;

    vector<int> each(howMany);
    
    for(int i = 0; i < howMany; i++)
    {
        cin >> each[i];
        if(i != howMany - 1) each[i]--;
        available += each[i];
    }

    cout << available << endl;
    
    return 0;
}