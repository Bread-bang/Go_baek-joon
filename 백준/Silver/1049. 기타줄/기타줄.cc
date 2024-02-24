#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 끊어진 기타줄의 개수
    int M; // 기타줄 브랜드의 개수
    int package_min = 1001, single_min = 1001;

    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int input_package_cost, input_single_min;
        cin >> input_package_cost >> input_single_min;
        package_min = min(package_min, input_package_cost);
        single_min = min(single_min, input_single_min);
    }

    int total = (N / 6) * min(package_min, single_min * 6) + min(package_min, single_min * (N % 6));
    
    cout << total << "\n";
    
    return 0;
}