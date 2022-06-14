#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    
    for(int i=0; i<progresses.size(); i++){
        days.push((100-progresses[i])/speeds[i]);
    }
    
    while(!days.empty()){
        int max = days.front();
        int count = 1;
        days.pop(); 
        while(!days.empty() && days.front() <= max) {
            days.pop();
            count++;
        }
        answer.push_back(count);
    }
    
    return answer;
}