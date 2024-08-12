#include <iostream>
#include <vector>
#include <string>

using namespace std;

void drawBoard(char board[8][8], bool isWhite);
void checkMinValue(int x, int y, vector<vector<char> >& origin, char compBoard[8][8]);

int minValue;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char W[8][8];
    char B[8][8];

    drawBoard(W, true);
    drawBoard(B, false);

    int N, M;
    cin >> N >> M;
    cin.ignore();

    minValue = 64;
    vector<vector<char> > board(N, vector<char>(M));

    string str = "";
    for(int i = 0; i < N; i++)
    {
        getline(cin, str);
        for(int j = 0; j < M; j++)
        {
            board[i][j] = str[j];
        }
    }

    for(int i = 0; i <= N - 8; i++)
    {
        for(int j = 0; j <= M - 8; j++)
        {
            checkMinValue(i, j, board, W);
            checkMinValue(i, j, board, B);
        }
    }

    cout << minValue << "\n";

    return 0;
}

void checkMinValue(int x, int y, vector<vector<char> >& origin, char compBoard[8][8])
{
    int tempMin = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(origin[i + x][j + y] != compBoard[i][j])
                tempMin++;
        }
    }

    minValue = min(minValue, tempMin);
}

void drawBoard(char board[8][8], bool isWhite)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = (isWhite) ? 'W' : 'B';
            isWhite = !isWhite; 
        }
        isWhite = !isWhite; 
    }
}