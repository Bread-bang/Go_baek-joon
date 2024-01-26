#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    char c;
    double result[N];
    for(int i = 0; i < N; i++)
    {
        double d;
        cin >> d;
        cin.ignore();

        string line;
        getline(cin, line);

        for(char c : line)
        {
            if(c == '@')
                d *= 3;
            else if(c == '%')
                d += 5;
            else if(c == '#')
                d -= 7;
        }
        result[i] = d;
    }

    for(double val : result)
        cout << fixed << setprecision(2) << val << endl;

    return 0;
}