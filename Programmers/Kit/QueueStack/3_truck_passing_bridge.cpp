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
        if(tq.size()<=bridge_length){
            int next = q.front();
            if(cw+next<=weight){
                q.pop();
                tq.push(next);
                cw+=next;
                answer++;
            }
            else{
                cw-=tq.front();
                if(cw==0 && q.size()==1){
                    answer++;
                    break;
                }
                tq.pop();
                answer++;
            }
        }
    }
    
    int remain=0;
    remain=bridge_length;
    
    answer+=remain;
    
    return answer;
}