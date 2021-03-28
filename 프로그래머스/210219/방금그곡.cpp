#include <bits/stdc++.h>
using namespace std;
//완전 탐색
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int anstime = 0;
    int size = musicinfos.size();
    vector<string> mvector;
    for (int i = 0; i < m.size(); i++) {
        string temp = "";
        temp += m[i];
        if (i + 1 < m.size()) {
            if (m[i + 1] == '#') {
                temp += '#';
                i++;
            }
        }
        mvector.push_back(temp);
    }
    int msize = mvector.size();
    for (int i = 0; i < size; i++) {
        int prev_hour = 0, prev_min = 0, now_hour = 0, now_min = 0;
        prev_hour = stoi(musicinfos[i].substr(0, 2)); prev_min = stoi(musicinfos[i].substr(3, 2));
        now_hour = stoi(musicinfos[i].substr(6, 2)); now_min = stoi(musicinfos[i].substr(9, 2));
        int time = now_hour * 60 + now_min - prev_hour * 60 - prev_min;
        if (time <= anstime)continue;
        //, 을 기준으로 name과 음계 구분
        bool flag = false;
        string title = "", m2;
        vector <string> m2vector;
        for (int j = 12; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j] == ',') {
                flag = true;
                continue;
            }
            if (flag)m2 += musicinfos[i][j];
            else title += musicinfos[i][j];
        }
        int m2size = 0;
        for (int j = 0; j < m2.size(); j++) {
            string temp = "";
            temp += m2[j];
            if (j + 1 < m2.size()) {
                if (m2[j + 1] == '#') {
                    temp += '#';
                    j++;
                }
            }
            m2vector.push_back(temp);
            m2size++;
            if (m2size == time)break;
        }
        for (int j = 0; j < m2size; j++) {
            flag = true;
            for (int k = 0; k < msize; k++) {
                if (mvector[k] != m2vector[(j + k) % m2size]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                anstime = time;
                answer = title;
                break;
            }
        }
    }
    return answer;
}