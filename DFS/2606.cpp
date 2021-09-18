/* [# 2606] 바이러스 */
#include <iostream>
using namespace std;

int map[101][101] = {0};
int visit[101] = {0};
int computer_num;
int answer = 0;

void dfs(int n)
{
    answer++;
    visit[n] = 1;
    for (int i = 1; i <= computer_num; i++)
    {
        if (map[n][i] && !visit[i])
            dfs(i);
    }
}

int main()
{
    int link_num, A, B;
    cin >> computer_num; // 컴퓨터의 수
    cin >> link_num;     // 직접 연결 수

    for (int i = 0; i < link_num; i++)
    {
        cin >> A >> B; // 직접 연결
        map[A][B] = map[B][A] = 1;
    }

    dfs(1);
    printf("%d", answer - 1);
    return 0;
}