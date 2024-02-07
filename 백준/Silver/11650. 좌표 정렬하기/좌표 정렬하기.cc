#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> p;
vector<pair<int, int> > coordinate;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        coordinate.push_back(make_pair(a, b));
    }

    sort(coordinate.begin(), coordinate.end(), compare);

    for(auto pair : coordinate)
        cout << pair.first << " " << pair.second << "\n";

    return 0;
}