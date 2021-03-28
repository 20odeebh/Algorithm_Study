#include <bits/stdc++.h>
using namespace std;
int d[11];
map<string, bool> Map;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    for (int i = 1; i <= n; i++)d[i] = 0;
    int size = words.size();
    //끝글자와 순서의 번호를 대신하는 start 변수를 두어 계산
    char last = words[0][0], start = 1;

    for (int i = 0; i < size; i++) {
        d[start]++;
        if (Map[words[i]] || words[i].size() == 1 || words[i][0] != last) {
            answer.push_back(start);
            answer.push_back(d[start]);
            return answer;
        }
        last = words[i][words[i].size() - 1];
        Map[words[i]] = true;
        start++;
        if (start > n)start = 1;
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}