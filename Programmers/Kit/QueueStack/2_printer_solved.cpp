#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 0;
    
    queue<pair<int,int>> q;
    priority_queue <int> pq;
    
    for(int i=0; i<priorities.size(); i++){
        q.push(make_pair(i,priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if(pq.top() == value){
            pq.pop();
            count++;
            if(location == index){
                answer = count;
                break;
            }
        }
        else{
            q.push(make_pair(index,value));
        }
    }
    
    return answer;
}