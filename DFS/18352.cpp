// [# 18352] 특정 거리의 도시 찾기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> q;
vector<int> edge[300001]; //간선정보
bool visited[300001];     // 방문정보
int N, M, K, X;
int loadlength;

void sortResult()
{
    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front());
        q.pop();
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}

void BFS(int X)
{
    q.push(X);
    visited[X] = true;
    while (1)
    {
        if (q.empty())
        {
            cout << -1 << '\n';
            break;
        }
        if (loadlength == K)
        {
            sortResult();
            break;
        }
        int qsize = q.size();
        while (qsize--)
        {
            int start = q.front();
            cout << "start: " << start << endl;
            cout << "edge[start].size(): " << edge[start].size() << endl;
            for (int i = 0; i < edge[start].size(); i++)
            {
                if (visited[edge[start][i]] == false)
                {
                    cout << "i: " << i << endl;
                    cout << "edge[start][i]: " << edge[start][i] << endl;
                    q.push(edge[start][i]);
                    visited[edge[start][i]] = true;
                }
            }
            q.pop();
        }
        loadlength++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X
    int x, y;
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
    }

    BFS(X);

    return 0;
}