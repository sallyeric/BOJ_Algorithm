#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> substring_map;

    for(auto number: phone_book) {
        string temp="";
        for(int i = 0; i < number.size()-1; i++) {
            temp+=number[i];
            if(substring_map.find(temp)!=substring_map.end()){
                continue;
            }
            substring_map.insert({temp, 1});
        }
    }
    
    // for(auto it=substring_map.begin();it!=substring_map.end();it++){
    //     cout << it->first << ' ' << it->second << '\n';
    // }
    
    for(auto number: phone_book) {
        // cout << substring_map[number] << ' ' << number << '\n'
;        if(substring_map[number] == 1) {
            return false;
        }
    }
    
    
    return answer;
}