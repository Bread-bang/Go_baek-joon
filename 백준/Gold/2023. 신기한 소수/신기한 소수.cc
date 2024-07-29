#include <iostream>
#include <vector>

using namespace std;

void DFS(int num, int N);
bool isPrime(int num);

vector<int> init = {2, 3, 5, 7};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < init.size(); i++)
        DFS(init[i], N);

    return 0;
}

void DFS(int num, int N)
{
    if(!isPrime(num))
        return ;

    if(N == 1)
    {
        cout << num << "\n";
        return ;
    }

    for(int i = 1; i <= 9; i += 2)
    {
        int next_num = num * 10 + i;

        if(isPrime(next_num))
            DFS(next_num, N - 1);
    }
}

bool isPrime(int num)
{
    for(int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}