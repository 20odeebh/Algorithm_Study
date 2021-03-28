#include <bits/stdc++.h>
using namespace std;
//해시

//장르마다 플레이된 곡 수
map<string, int> genres_plays;
//중복장르 제거용 체크 맵
map<string, bool> genres_check;
//장르마다 플레이된 곡들의 수와 인덱스를 맥스힙에 넣어서 사용
map<string, priority_queue<pair<int, int>>> Map;
//장르마다 플레이된 곡수와 장르이름을 맥스힙에 넣어서 사용
priority_queue<pair<int, string>> pq;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = plays.size();
    for (int i = 0; i < n; i++) {
        genres_plays[genres[i]] += plays[i];
        Map[genres[i]].push({ plays[i],n - i });
    }

    for (int i = 0; i < n; i++) {
        if (genres_check[genres[i]] == false) {
            genres_check[genres[i]] = true;
            pq.push({ genres_plays[genres[i]],genres[i] });
        }
    }
    while (!pq.empty()) {
        for (int i = 0; i < 2; i++) {
            if (Map[pq.top().second].empty())break;
            answer.push_back(n - Map[pq.top().second].top().second);
            Map[pq.top().second].pop();
        }
        pq.pop();
    }

    return answer;
}