#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int,int>> v;
    
    for(int i=0; i<priorities.size(); i++){
        v.push_back(make_pair(i,priorities[i]));
    }
    
    // for(int i=0; i<v.size(); i++){
    //     cout << v[i].second;
    // }
    
    int v_size = v.size();
    int cnt = 1;
    while(v_size > 0){
        if(v_size==1){
            answer = cnt;
            break;
        } 
        pair<int,int> max=v[0];
        cout << "first index: " << max.first << " value: " << max.second << "\n";
        int max_pos=v[0].first;
        for(int i=1; i<v.size(); i++){
            if(v[i].second > max.second){
                max=v[i];
                max_pos=v[i].first;
            }
        }
        
        // if(max_pos == location){
        //     answer = cnt;
        //     break;
        // }

        cout << "max: " << max.second << "\n";
        cout << "max_pos: " << max_pos << "\n";

        vector<pair<int,int>> front;
        if(max_pos != 0) {
            for(int i=0; i<max_pos; i++){
                front.push_back(v[i]);
            }
        }

        vector<pair<int,int>> back;
        for(int i=max_pos+1; i<v.size(); i++){
            back.push_back(v[i]);
        }

        for(int i=0; i<back.size(); i++){
            v[i] = back[i];
        }

        for(int i=0; i<front.size(); i++){
            v[i+back.size()] = front[i];
        }

        if(v.size()!=1) v.pop_back();
        for(int i=0; i<v.size(); i++){
            cout << v[i].first;
        }
        cout << "\n";
        
        v_size--;
        cnt++;
    }
    

    
    // while(v.size() != 0){
    //     //find max of cur vector
    //     //save smaller index items in temp
    //     //move bigger index items to the front
    // }
    
    return answer;
}