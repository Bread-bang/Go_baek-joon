#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr_original(N + 1, vector<int>(N + 1, 0));
    vector<vector<int> > arr_Sum(N + 1, vector<int>(N + 1, 0));

    int i, j;
    
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
        {
            cin >> arr_original[i][j];
        }
    }

    // 1행, 1열 채우기
    arr_Sum[1][1] = arr_original[1][1];
    for(j = 2; j <= N; j++)
    {
        arr_Sum[1][j] = arr_Sum[1][j - 1] + arr_original[1][j];
        arr_Sum[j][1] = arr_Sum[j - 1][1] + arr_original[j][1];
    }

    // 나머지 행과 열의 구간합 채우기
    for(int i = 2; i <= N; i++)
    {
        for(int j = 2; j <= N; j++)
        {
            arr_Sum[i][j] = arr_Sum[i][j - 1] + arr_Sum[i - 1][j] - arr_Sum[i - 1][j - 1] + arr_original[i][j];
        }
    }

    int x1, y1, x2, y2;
    int answer;
    for(int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        // 질의에 대한 답 구하기
        answer = arr_Sum[x2][y2] - arr_Sum[x1 - 1][y2] - arr_Sum[x2][y1 - 1] + arr_Sum[x1 - 1][y1 - 1];
        cout << answer << "\n";
    }

    return 0;
}