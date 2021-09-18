// 1. [BOJ 13460] 구슬탈출2
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

string board[12];
int visit[12][12];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> QR;
    queue<pair<int, int>> QB;

    pair<int, int> exit;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == '.')
                visit[i][j] = -1;
            if (board[i][j] == 'O')
            {
                visit[i][j] = -2;
                exit.X = i;
                exit.Y = j;
            }
            if (board[i][j] == 'R')
                QR.push({i, j});
            if (board[i][j] == 'B')
                QB.push({i, j});
        }
    }

    // B구슬 BFS 처리
    while (!QB.empty())
    {
        pair<int, int> cur = QB.front();
        QB.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int tmp = visit[cur.X][cur.Y] + 1;
            if (nx <= 0 || nx >= M || ny <= 0 || ny >= M)
                continue;
            if (visit[nx][ny] == -2)
            {
                visit[nx][ny] = tmp;
                break;
            }
            if (visit[nx][ny] == -1)
            {
                visit[nx][ny] = tmp;
                QB.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    // R구슬 BFS 처리
    int ans = 0;
    while (!QR.empty())
    {
        pair<int, int> cur = QR.front();
        QR.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int tmp = visit[cur.X][cur.Y] + 1;
            if (nx <= 0 || nx >= M || ny <= 0 || ny >= M)
                continue;
            if ((exit.X = nx && exit.Y == ny) && (visit[nx][ny] == -2 || tmp < visit[nx][ny]))
            {
                ans = tmp;
                cout << ans;
                return 0;
            }
            if (visit[nx][ny] == -1 || (visit[nx][ny] > 0 && visit[nx][ny] > tmp))
            {
                visit[nx][ny] = tmp;
                ans = tmp;
                QR.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "-1";
    // DEBUG
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}