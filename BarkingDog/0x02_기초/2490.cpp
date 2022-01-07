// [BOJ 2490] 윷놀이
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int result[3][4] = {};
    char answer[3] = {};

    for(int i = 0; i < 3; i++){
        int count = 0;
        for(int j = 0; j < 4; j++){
            int num;
            cin >> num;
            if(num == 1) count ++;
        }
        if(count == 3) answer[i] = 'A';
        else if(count == 2) answer[i] = 'B';
        else if(count == 1) answer[i] = 'C';
        else if(count == 0) answer[i] = 'D';
        else if(count == 4) answer[i] = 'E';
    }

    for(int i = 0; i < 3; i++){
        cout << answer[i] << "\n";
    }
}