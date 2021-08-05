// 1. [BOJ 1926] 그림
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n, m; // 세로, 가로
    int board[502][502];
    int visit[502][502];

    int num = 0, mx = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 || visit[i][j])
                continue;
            num++;
            queue<pair<int, int>> Q;
            visit[i][j] = 1;
            Q.push({i, j});
            int area = 0;
            while (!Q.empty())
            {
                area++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (board[nx][ny] != 1 || visit[nx][ny])
                        continue;
                    visit[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }

    cout << num << '\n'
         << mx;

    return 0;
}