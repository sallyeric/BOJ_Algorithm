// 4. [BOJ 4179] 불!
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int R, C; // 행, 열
int board[1002][1002];
int jihun[1002][1002]; // 지훈 방문
int fire[1002][1002];  // 불 방문

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
}