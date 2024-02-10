#include <iostream>
#include <set>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    set<int> s;

    cin >> N;

    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        s.insert(num);
    }
    
    for(int num : s)
        cout << num << " ";

    return 0;
}