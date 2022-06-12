#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm> // find 사용

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    vector<string> garr; // genre array
    vector<vector<int>> gparr; // plays array by genre
    vector<int> sarr; // plays sum array by genre
    unordered_map<int, int> pidx; // plays index (index, play)
    unordered_map<int, int> rpidx; // plays index (play, index)
    unordered_map<int, string> gidx; // genres index
    unordered_map<int, int> sidx; // sum index

    for(int i=0; i<plays.size(); i++) {
        pidx[i] = plays[i];
    }
    
    for(int i=0; i<plays.size(); i++) {
        rpidx[plays[i]] = i;
    }
    
    for(int i=0; i<genres.size(); i++) {
        gidx[i] = genres[i];
    }
    
    // for(auto i=pidx.begin(); i!=pidx.end(); i++) {
    //     cout << i->first << ' ' << i->second << '\n';   
    // }
    
    // 장르 배열 만들기
    for(auto genre: genres) {
        if(find(garr.begin(), garr.end(), genre) != garr.end()) continue;
        garr.push_back(genre);
    }
    
    // for(int i=0; i<garr.size(); i++) cout << garr[i];
    
    // 장르별 재생횟수 배열 만들기
    for(int i=0; i<garr.size(); i++) {
        vector<int> parr; // plays of each genre
        for(auto it=gidx.begin(); it!=gidx.end(); it++){
            if(it->second == garr[i]) parr.push_back(pidx[it->first]);
        }
        sort(parr.rbegin(), parr.rend());
        gparr.push_back(parr);
    }
    
    
    // for(int i=0; i<gparr.size(); i++){
    //     for(int j=0; j<gparr[i].size(); j++) {
    //         cout << gparr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // 합계 배열 만들기
    for(int i=0; i<gparr.size(); i++){
        int sum=0;
        for(int j=0; j<gparr[i].size(); j++) {
            sum+=gparr[i][j];
        }
        sarr.push_back(sum);
        sidx[sum] = i;
    }
    
    // for(int i=0;i<sarr.size();i++) cout << sarr[i] << ' ';
    
    // for(auto i=sidx.begin(); i!=sidx.end(); i++) {
    //     cout << i->first << ' ' << i->second << '\n';   
    // }
    
    sort(sarr.rbegin(), sarr.rend());
    for(int i=0; i<sarr.size(); i++){
        int g_idx = sidx[sarr[i]];
        for(int j=0; j<2; j++) {
            // cout << gparr[g_idx][k] << ' ';
            int play = gparr[g_idx][j];
            // cout << rpidx[play] << ' ';
            answer.push_back(rpidx[play]);
        }
    }
    
    return answer;
}