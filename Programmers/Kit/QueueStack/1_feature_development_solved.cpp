#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 깔끔하게 떨어지지 않는 날에는 +1을 해줘야한다.
// 예, 진도 95% 속도 4% 라면 하루만이 아닌 이틀쨰에 배포된다.
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    
    for(int i=0; i<progresses.size(); i++){
        int val = 0;
        if((100-progresses[i])%speeds[i] != 0) 
            val = (100-progresses[i])/speeds[i]+1;
        else val = (100-progresses[i])/speeds[i];
        days.push(val);
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