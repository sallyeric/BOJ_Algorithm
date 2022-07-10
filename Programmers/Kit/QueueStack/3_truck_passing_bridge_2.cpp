#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    queue<int> tq;
    
    for(int i=0; i<truck_weights.size(); i++){
        q.push(truck_weights[i]);
    }
    
    int cw=0; // current weight
    while(!q.empty()){
        answer++;
        int tmp = q.front();
        if(tq.size()<bridge_length && cw+tmp<=weight) {
            q.pop();
            tq.push(tmp);
            cw+=tmp;
        }
        else if(tq.size()<bridge_length && cw+tmp>weight) {
            answer+=bridge_length-tq.size();
            cw-=tq.front();
            tq.pop();
        }
        else {
            cw-=tq.front();
            tq.pop();
        }
        cout << "answer: " << answer << "\n";
        cout << "tmp: "<< tmp<< "\n";
        cout << "q.size(): " << q.size()<< "\n";
        cout << "tq.size(): " << tq.size()<< "\n";
        cout << "cw: "<< cw<< "\n";
    }
    
    // if(q.empty() && !tq.empty()) answer+=1;
    
    if(tq.size==1) answer+=bridge_length;
    
    return answer;
}