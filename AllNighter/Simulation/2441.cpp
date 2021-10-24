// 1. [BOJ 2441] 별찍기 4
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        int stars = num - i;
        int buffers = i;
        for(int j=0; j<buffers; j++){
            cout << " ";
        }
        for(int k=0; k<stars; k++){
            cout << "*";
        }
        cout << "\n";
    }
}