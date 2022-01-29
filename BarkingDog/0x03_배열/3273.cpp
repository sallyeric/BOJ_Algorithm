// [BOJ 3273] 두 수의 합
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    int arr[1000001] = {};

    // 입력
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    // 풀이
    int answer = 0;
    bool visited[2000001];
    for(int i = 0; i < n; i++) {
        if(x - arr[i] > 0 && visited[x - arr[i]] == true) answer++;
        visited[arr[i]] = true;
    }
    
    cout << answer;
}