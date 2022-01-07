//  [BOJ 10871] X보다 작은 수
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    cin >> N >> X;

    vector<int> A;
    vector<int> answer;

    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(num < X)
            A.push_back(num);
    }

    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }

    return 0;
}