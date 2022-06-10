#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> um;
    
    for(auto item: clothes) {
        //  이렇게 하지 않아도 item[1]이 map에 없다면 문자열 넣고, 1을 자동으로 넣는 듯
        // if(um.find(item[1])==um.end()) um.insert({item[1], 1});
        // else um[item[1]]++;
        um[item[1]]++;
    }
    
    int temp=1;
    for(auto it=um.begin(); it!=um.end(); it++) {
        temp *= it->second + 1;
    }
    
    answer = temp-1;
    
    return answer;
}s