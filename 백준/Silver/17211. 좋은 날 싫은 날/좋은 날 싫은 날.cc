#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j, k, m;
    int squareNum, condition;
    vector< vector<double> > p(2, vector<double>(2, 0.0));
    vector< vector<double> > temp(2, vector<double>(2, 0.0));
    vector< vector<double> > result(2, vector<double>(2, 0.0));

    cin >> squareNum >> condition;

    for(i = 0; i < p.size(); i++)
    {
        for(j = 0; j < p[i].size(); j++)
            cin >> p[i][j];
    }
    temp = p;
    for(i = 0; i < squareNum - 1; i++)
    {
        fill(result.begin(), result.end(), vector<double>(2, 0.0));
        for(j = 0; j < 2; j++)
        {
            for(k = 0; k < 2; k++)
            {
                for(m = 0; m < 2; m++)
                {
                    result[j][k] += temp[j][m] * p[m][k];
                }
            }
        }
        temp = result;
    }

    i = (condition == 0) ? 0 : 1;
    for(j = 0; j < 2; j++)
        cout << round(result[i][j] * 1000) << "\n";

    return 0;
}