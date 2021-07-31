#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    int arr[100005];

    cin >> N >> X;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < X)
        {
            cout << arr[i] << ' ';
        }
    }

    return 0;
}