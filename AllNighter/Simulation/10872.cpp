// 3. [BOJ 10872] 팩토리얼
#include <iostream>

using namespace std;

int factorial(int num){
    if(num == 1)
        return 1;
    
    return num * factorial(num-1);
}

int main()
{
    int num; 
    cin >> num;

    int answer = 1;

    if(num != 0)
        answer = factorial(num);

    cout << answer;
}
