// 2. [BOJ 5598] 카이사르 암호
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    for (int i=0; i<len; i++){
        if(str[i] != 'A' && str[i] != 'B' && str[i] != 'C')
            str[i] = str[i]-3;
        else if(str[i] == 'A')
            str[i] = 'X';
        else if(str[i] == 'B')
            str[i] = 'Y';
        else if(str[i] == 'C')
            str[i] = 'Z';
    }
    cout << str<<'\n';
}