#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
    int i, j, C;
    cin >> C;
    
    vector<vector <int>> v_eachLine(C);
    int eachLine_cnt, score;
    for(i = 0; i < C; i++)
    {
        cin >> eachLine_cnt;
        for(j = 0; j < eachLine_cnt; j++)
        {
            cin >> score;
            v_eachLine.at(i).push_back(score);
        }
    }

    vector<double> v_sum;
    vector<double> v_avg;
    for(vector<int> a : v_eachLine)
    {
        v_sum.push_back(accumulate(a.begin(), a.end(), 0.0));
        v_avg.push_back(v_sum.back() / a.size());
    }

    vector<double> results;
    vector<int> v_over_avg_cnt;
    int over_avg_cnt = 0;
    for(i = 0; i < v_eachLine.size(); i++)
    {
        for(j = 0; j < v_eachLine[i].size(); j++)
        {
            if(v_avg[i] < v_eachLine[i][j])
                over_avg_cnt++;
        }
        v_over_avg_cnt.push_back(over_avg_cnt);
        over_avg_cnt = 0;
    }

    for(int i = 0; i < v_over_avg_cnt.size(); i++)
        cout << showpoint << setprecision(5) << v_over_avg_cnt[i] / (double)v_eachLine[i].size() * 100 << "%" << endl;

    return 0;
}