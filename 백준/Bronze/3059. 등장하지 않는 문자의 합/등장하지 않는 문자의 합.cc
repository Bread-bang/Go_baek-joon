#include <iostream>
#include <set>

using namespace std;

int main(){

    int N , sum;
    cin >> N;

    while(N--)
    {
        set<char> s;
        string input;
        cin >> input;
        sum = 0;

        for(int i = 0; i < input.size(); i++)
            s.insert(input[i]);
        
        for(char item : s)
            sum += (int)item;
        
        cout << 2015 - sum << "\n";
    }
    
    return 0;
}