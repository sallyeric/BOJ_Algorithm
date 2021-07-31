// 알파벳 개수
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    for (char c = 'a'; c <= 'z'; c++)
    {
        int cnt = 0;
        for (auto e : word)
        {
            if (c == e)
                cnt++;
        }
        cout << cnt << ' ';
    }

    return 0;
}