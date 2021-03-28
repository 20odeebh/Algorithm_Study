#include <bits/stdc++.h>
using namespace std;
//완전 탐색
int pos[130];
int solution(int n, vector<string> data) {
    int answer = 0;
    string kakao = "ACFJMNRT";
    sort(kakao.begin(), kakao.end());
    int size = data.size();
    vector<int> intdata;
    for (int i = 0; i < size; i++) {
        intdata.push_back(data[i][4] - '0');
    }
    do {
        for (int i = 0; i < kakao.size(); i++) {
            pos[kakao[i]] = i;
        }
        bool flag = true;
        for (int i = 0; i < size; i++) {
            int distance = abs(pos[data[i][0]] - pos[data[i][2]]) - 1;
            if (data[i][3] == '<') {
                if (distance >= intdata[i]) {
                    flag = false;
                    break;
                }
            }
            else if (data[i][3] == '>') {
                if (distance <= intdata[i]) {
                    flag = false;
                    break;
                }
            }
            else {
                if (distance != intdata[i]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)answer++;
    } while (next_permutation(kakao.begin(), kakao.end()));

    return answer;
}