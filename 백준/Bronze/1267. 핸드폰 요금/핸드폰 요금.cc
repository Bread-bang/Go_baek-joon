/**
 * 
 * 영식(Y)
 * 30초마다 10원씩
 *    0 ~ 29초 : 10원
 *   30 ~ 59초 : 20원
 *   60 ~ 89초 : 30원
 *         ...
 * 
 * 민식(M)
 * 60초마다 15원씩
 *    0 ~ 59초 : 15원
 *   60 ~ 119초 : 30원
 *  120 ~ 179초 : 45원
 * 
 */

#include <iostream>
#include <vector>
#define Y_30 30
#define M_60 60

using namespace std;

int main()
{
    int N;
    int totalCost = 0;
    cin >> N;

    vector<int> minute(N);
    vector<int> Y(N);
    vector<int> M(N);

    int Y_share, M_share;
    int Y_sum = 0, M_sum = 0;

    for(int i = 0; i < N; i++)
    {
        cin >> minute[i];
        Y_share = minute[i] / Y_30;
        M_share = minute[i] / M_60;

        Y[i] = (Y_share + 1) * 10;
        M[i] = (M_share + 1) * 15;

        Y_sum += Y[i];
        M_sum += M[i];
    }

    if(Y_sum > M_sum)
        cout << "M " << M_sum << endl;
    else if(Y_sum == M_sum)
        cout << "Y M " << Y_sum << endl;
    else
        cout << "Y " << Y_sum << endl;
    return 0;
}