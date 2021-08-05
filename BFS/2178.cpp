// 2. [BOJ 2178] 미로탐색
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // int board[102][102];
    string board[102];   // ** 문제조건 ** 각 열마다 붙여서 입력
    int visit[102][102]; // visit에 출발지로부터 거리 저장

    int N, M;
    int ans = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visit[i][j] = -1;
        }
    }

    queue<pair<int, int>> Q;
    visit[0][0] = 0;
    Q.push({0, 0});

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
            if (visit[nx][ny] >= 0 || board[nx][ny] != '1')
                continue;
            visit[nx][ny] = visit[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    cout << visit[N - 1][M - 1] + 1;

    return 0;
}