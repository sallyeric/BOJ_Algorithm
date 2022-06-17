#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int,int> q;
    
    for(int i=0; i<priorities.size(); q++){
        q.push(make_pair(i,priorities[i]));
    }
    
    queue<int,int> temp;
    while(!q.empty()){
        pair<int,int> max = q.front();
        q.pop();
        if(q.front() > max){
            
        }
        temp.push_back(max);
        
    }
    
    return answer;
}