#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm> // find 사용

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> music;
    map<string, map<int, int>> musiclist;
    
    for(int i=0; i<genres.size(); i++) {
        music[genres[i]] += plays[i];
        musiclist[genres[i]][i] = plays[i]; 
    }
    
    // for(auto it=musiclist["classic"].begin(); it!=musiclist["classic"].end(); it++) {
    //     cout << it->first << " " << it->second << "\n";
    // }
    
    while(music.size() > 0) {
        string genre{};
        int max{0};
        for(auto mu: music) {
            if(max < mu.second) {
                max = mu.second;
                genre = mu.first;
            }
        }
        
        for(int i=0; i<2; i++) {
            int val = 0;
            int idx = -1;
            for(auto ml: musiclist[genre]) {
                if(val < ml.second) {
                    val = ml.second;
                    idx = ml.first;
                }
            }
            if(idx == -1) break;
            answer.push_back(idx);
            musiclist[genre].erase(idx);
        }
        music.erase(genre);
    }
    
    return answer;
}