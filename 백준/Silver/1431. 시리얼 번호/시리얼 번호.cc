#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(tuple<string, int, int> a, tuple<string, int, int> b)
{
    if(get<1>(a) != get<1>(b))
        return get<1>(a) < get<1>(b);
    else
    {
        if(get<2>(a) != get<2>(b))
            return get<2>(a) < get<2>(b);
        else
            return get<0>(a) < get<0>(b);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<tuple<string, int, int> > v_info;

    int input_length;
    int input_sum = 0;
    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        input_length = input.length();
        for(int j = 0; j < input_length; j++)
        {
            if(isdigit(input[j]))
            {
                input_sum += input[j] - '0';
            }
        }

        v_info.push_back(make_tuple(input, input_length, input_sum));
        input_sum = 0;
    }

    sort(v_info.begin(), v_info.end(), compare);

    for(auto item : v_info)
        cout << get<0>(item) << "\n";

    return 0;
}