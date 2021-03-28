#include <bits/stdc++.h>
using namespace std;
//민힙 맥스힙 2개에 푸쉬한후 
//delete할때는 숫자들의 카운트를 센다.
//만약 힙의 top의 카운트가 0이라면 다 빼준다.
priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int> pq2;
map<int, int> cnt;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int size = operations.size();
    for (int i = 0; i < size; i++) {
        if (operations[i][0] == 'I') {
            int num = 0;
            bool minus_flag = false;
            int j = 2;
            if (operations[i][j] == '-') {
                minus_flag = true;
                j++;
            }
            while (j < operations[i].size()) {
                num *= 10;
                num += (operations[i][j] - '0');
                j++;
            }
            if (minus_flag)num = -num;
            cout << num << '\n';
            pq1.push(num);
            pq2.push(num);
            cnt[num]++;
        }
        else {
            if (operations[i][2] != '-') {
                if (pq2.empty())continue;
                if (cnt[pq2.top()] == 0)continue;
                cnt[pq2.top()]--;
                pq2.pop();
                while (!pq1.empty()) {
                    if (cnt[pq1.top()] == 0)pq1.pop();
                    else break;
                }
                while (!pq2.empty()) {
                    if (cnt[pq2.top()] == 0)pq2.pop();
                    else break;
                }
            }
            else {
                if (pq1.empty())continue;
                if (cnt[pq1.top()] == 0)continue;
                cnt[pq1.top()]--;
                pq1.pop();
                while (!pq1.empty()) {
                    if (cnt[pq1.top()] == 0)pq1.pop();
                    else break;
                }
                while (!pq2.empty()) {
                    if (cnt[pq2.top()] == 0)pq2.pop();
                    else break;
                }
            }
        }
    }
    if (pq1.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(pq2.top());
        answer.push_back(pq1.top());
    }
    for (int i = 0; i < answer.size(); i++)cout << answer[i] << ' ';
    cout << '\n';
    return answer;
}