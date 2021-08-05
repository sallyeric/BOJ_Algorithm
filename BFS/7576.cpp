// 3. [BOJ 7576] 토마토
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int N, M;              // 가로, 세로
int board[1002][1002]; // ** 참고 ** 자동으로 0 채워짐
int visit[1002][1002]; // 걸린 일수 표시

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    queue<pair<int, int>> Q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            {
                Q.push({i, j}); // 시작점이 될 토마토들을 queue에 밀 넣어둔다
            }
            if (board[i][j] == 0) // 아직 익지 않은 토마토는
            {
                visit[i][j] = -1; // 일수를 -1로 두어 처리 대상으로 만든다
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visit[nx][ny] >= 0) // 이미 방문했거나 (visit > 0) 토마토가 없는 경우 (visit = 0) 건너뜀
                continue;

            visit[nx][ny] = visit[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visit[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            ans = max(ans, visit[i][j]);
        }
    }
    cout << ans;
}