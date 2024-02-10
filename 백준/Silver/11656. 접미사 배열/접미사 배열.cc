#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    int cnt = input.size();
    vector<string> v;

    v.emplace_back(input);

    for(int i = 0; i < cnt - 1; i++)
    {
        input.erase(0, 1);
        v.emplace_back(input);
    }

    sort(v.begin(), v.end());

    for(string item : v)
        cout << item << "\n";

    return 0;
}