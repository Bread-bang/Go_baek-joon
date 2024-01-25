#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int cnt = (N - 1) + (M - 1) * N;

    cout << cnt << "\n";

    return 0;
}