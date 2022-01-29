// [BOJ 1475] 방 번호
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int visited[10] = {};
    int max = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] - '0' == 6 || str[i] - '0' == 9){
            visited[6]++;
            // if(visited[6]%2 == 0) visited[6] = visited[6]/2;
            // else visited[6] = visited[6]/2 + 1;
        }
        else visited[str[i] - '0']++;

        if(str[i] - '0' != 6 && str[i] - '0' != 9 && visited[str[i] - '0'] > max) max = visited[str[i] - '0'];
    }

    int sixNine = 0;
    if(visited[6]%2 == 0) sixNine = visited[6]/2;
    else sixNine = visited[6]/2 + 1;

    if(sixNine > max) max = sixNine;

    cout << max;
}