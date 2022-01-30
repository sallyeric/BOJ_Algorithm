// [BOJ 1919] 애너그램 만들기
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 알파벳 26자
    int arr1[26] = {};
    int arr2[26] = {};
    string str1, str2;
    cin >> str1;
    cin >> str2;

    for(int i = 0; i < str1.length(); i++){
        arr1[str1[i]-97]++;
    } 

    for(int i = 0; i < str2.length(); i++){
        arr2[str2[i]-97]++;
    } 

    int count = 0;
    for(int i = 0; i < 26; i++){
        if(arr1[i] > arr2[i]) count += arr1[i] - arr2[i];
        if(arr1[i] < arr2[i]) count += arr2[i] - arr1[i];
    }

    cout << count;
}