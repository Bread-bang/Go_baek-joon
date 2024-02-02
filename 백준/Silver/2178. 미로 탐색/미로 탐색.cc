#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<vector<int>> steps;
int direction[4][2] = {
    {-1, 0}, // 상
    {1, 0},  // 하
    {0, -1}, // 좌
    {0, 1}   // 우
};

void bfs(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    steps[start_x][start_y]++;
    visited[start_x][start_y] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int move_x = x + direction[i][0];
            int move_y = y + direction[i][1];

            if((move_x < N && move_x >= 0) && (move_y < M && move_y >= 0) && maze[move_x][move_y] == 1 && !visited[move_x][move_y])
            {
                q.push(make_pair(move_x, move_y));
                visited[move_x][move_y] = true;
                steps[move_x][move_y] = steps[x][y] + 1;
            }
        }
    }

    cout << steps[N - 1][M - 1];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    maze.resize(N);
    visited.resize(N);
    steps.resize(N);

    char input;
    for(int i = 0; i < N; i++)
    {
        maze[i].resize(M);
        visited[i] = vector<bool>(M, false);
        steps[i].resize(M, 0);
        for(int j = 0; j < M; j++)
        {
            cin >> input;
            maze[i][j] = input - '0';
        }
    }

    bfs(0, 0);

    return 0;
}