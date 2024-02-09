#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool compare(tuple<int, int, string>& a, tuple<int, int, string>& b)
{
    if(get<1>(a) == get<1>(b))
        return get<0>(a) < get<0>(b);
    
    return get<1>(a) < get<1>(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<tuple<int, int, string> > v_person;

    int age;
    string name;

    for(int i = 0; i < N; i++)
    {
        cin >> age >> name;
        v_person.push_back(make_tuple(i, age, name));
    }

    sort(v_person.begin(), v_person.end(), compare);

    for(auto person : v_person)
        cout << get<1>(person) << " " << get<2>(person) << "\n";

    return 0;
}