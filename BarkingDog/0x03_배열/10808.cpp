// [BOJ 10808] 알파벳 개수
#include <iostream>
#include <string>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[26] = {0};
    string input;
    cin >> input;

    for(int i = 0; i < input.length(); i++){
        int alp = input[i];
        arr[alp - 97] += 1;
    }

    for(int i = 0; i < 26; i++){
        cout << arr[i] << ' ';
    }
}