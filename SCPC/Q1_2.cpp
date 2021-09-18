#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int N;
vector<int> people;
vector<int> group;
vector<int> visit;

void DFS(int node)
{
    visit[node] = true;

    for (int i = 0; i < people[node].size(); i++)
    {
    }
}

int main(int argc, char **argv)
{
    int T, test_case;

    cin >> T;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        people.push_back(x);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visit[i])
        {
            DFS(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
