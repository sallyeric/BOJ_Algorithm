// 애너그램 만들기 (배열)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1;
    cin >> s2;

    vector<int> arr1(26);
    vector<int> arr2(26);

    for (char c = 'a'; c <= 'z'; c++)
    {
        int cnt = 0;
        for (auto c1 : s1)
        {
            if (c == c1)
            {
                arr1[c - 'a'] += 1;
            }
        }
        for (auto c2 : s2)
        {
            if (c == c2)
            {
                arr2[c - 'a'] += 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 26; i++)
    {
        int tmp = arr1[i] - arr2[i];
        if (tmp > 0)
            answer += tmp;
        else if (tmp < 0)
        {
            tmp *= -1;
            answer += tmp;
        }
    }

    cout << answer;

    return 0;
}