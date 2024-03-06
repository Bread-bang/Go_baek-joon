#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> prime_candidates;

    int N;
    cin >> N;

    int idx = 2;
    // 에라토스테네스의 체
    for(int i = 0; i <= N; i++)
    {
        prime_candidates.emplace_back(i);
    }
    
    for(int i = idx; i <= N; i++)
    {
        if(prime_candidates[i] == 0)
            continue;
        
        for(int j = 2 * i; j <= N; j+=i)
            prime_candidates[j] = 0;
    }

    while(N != 1)
    {
        if(N % prime_candidates[idx] == 0)
        {
            cout << prime_candidates[idx] << "\n";
            N /= prime_candidates[idx];
        }
        else
        {
            while(prime_candidates[++idx] == 0)
                ;
        }
    }

    return 0;
}