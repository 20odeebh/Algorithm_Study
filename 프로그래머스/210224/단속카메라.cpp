#include <bits/stdc++.h>
//슬라이딩 윈도우
//i번째마다 최소값, 최대값들을 저장해가면서 갱신
using namespace std;
pair<int, int> a[10001];
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int size = routes.size();
    for (int i = 0; i < size; i++) {
        a[i].first = routes[i][0];
        a[i].second = routes[i][1];
    }
    sort(a, a + size);
    int MIN = a[0].first, MAX = a[0].second;
    answer++;
    for (int i = 1; i < size; i++) {
        MIN = max(MIN, a[i].first);
        MAX = min(MAX, a[i].second);
        if (MIN > MAX) {
            answer++;
            MIN = a[i].first;
            MAX = a[i].second;
        }
    }

    return answer;
}