// 4. [BOJ 4179] 불!
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int R, C; // 행, 열
string board[1002];
int visit[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    queue<pair<int, int>> QJ;

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == '.')
                visit[i][j] = -1;
            if (board[i][j] == 'F')
                Q.push({i, j});
            if (board[i][j] == 'J')
                QJ.push({i, j});
        }
    }

    // 불에 대한 BFS 처리
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int tmp = visit[cur.X][cur.Y] + 1;
            if (nx < 0 || nx > R || ny < 0 || ny > C)
                continue;
            if (visit[nx][ny] == -1 || (visit[nx][ny] > 0 && tmp < visit[nx][ny]))
            {
                visit[nx][ny] = tmp;
                Q.push({nx, ny});
            }
        }
    }

    // 지훈이에 대한 BFS 처리
    int ans = 0;
    int fin_x = 0, fin_y = 0;
    pair<int, int> cur = QJ.front();

    while (!QJ.empty())
    {
        pair<int, int> cur = QJ.front();
        QJ.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int tmp = visit[cur.X][cur.Y] + 1;
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                cout << tmp;
                return 0;
            }
            if (visit[nx][ny] == -1 || (visit[nx][ny] > 0 && tmp < visit[nx][ny]))
            {
                visit[nx][ny] = tmp;
                ans = tmp;
                QJ.push({nx, ny});
            }
        }
    }

    cout << "IMPOSSIBLE";
}