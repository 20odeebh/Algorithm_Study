#include <bits/stdc++.h>
using namespace std;
//BFS 사용
queue<int> q;
int check[51];
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int size = words.size();
    int tIdx = -1;
    words.push_back(begin);
    for (int i = 0; i < size; i++) {
        if (words[i] == target) {
            tIdx = i;
            break;
        }
    }
    if (tIdx == -1)return 0;
    for (int i = 0; i < size; i++) {
        check[i] = 0;
    }
    check[size] = 1;
    q.push(size);
    while (!q.empty()) {
        int nowIdx = q.front();
        q.pop();
        for (int i = 0; i < size; i++) {
            if (check[i])continue;
            int difCnt = 0;
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] != words[nowIdx][j])difCnt++;
            }
            if (difCnt == 1) {
                check[i] = check[nowIdx] + 1;
                q.push(i);
            }
        }
    }
    if (check[tIdx]) {
        return check[tIdx] - 1;
    }
    return 0;
}