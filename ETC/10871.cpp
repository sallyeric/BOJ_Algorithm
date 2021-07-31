#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X, num;

    cin >> N >> X;

    while (N > 0)
    {
        cin >> num;
        if (num < X)
        {
            cout << num;
        }
    }
    return 0;
}