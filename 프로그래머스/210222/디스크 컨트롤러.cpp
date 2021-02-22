#include <bits/stdc++.h>
using namespace std;
struct A {
    int start, during;
    bool operator<(const A& p)const {
        if (start == p.start) {
            return during > p.during;
        }
        return start > p.start;
    }
};
// 작업을 시작하는 시점에서 가장 빨리 끝나는 작업 순서대로 끝낸다.
// 우선순위큐에 빨리 시작하는 순서대로 꺼낸 후 벡터에 저장
// 가장 시간 빨리 끝나는 인덱스를 찾아 빼고 다시 우선순위큐에 푸쉬
priority_queue<A> pq;
vector<A> v;
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    for (int i = 0; i < size; i++) {
        A a;
        a.start = jobs[i][0];
        a.during = jobs[i][1];
        pq.push(a);
    }
    int cnt = 1;
    int start = pq.top().start + pq.top().during;
    answer += pq.top().during;
    pq.pop();
    while (true) {
        if (cnt == size)break;
        while (!pq.empty()) {
            if (start >= pq.top().start) {
                v.push_back(pq.top());
                pq.pop();
            }
            else break;
        }
        int vsize = v.size();
        if (vsize) {
            int minTime = 999999999, idx = 0, minDuring = 999999999;
            for (int i = 0; i < vsize; i++) {
                int nowTime = start + v[i].during;
                if (minTime == nowTime) {
                    if (minDuring > v[i].during) {
                        idx = i;
                        minDuring = v[i].during;
                    }
                }
                if (minTime > nowTime) {
                    minTime = nowTime;
                    idx = i;
                    minDuring = v[i].during;
                    continue;
                }
            }
            answer += minTime - v[idx].start;
            start = minTime;
            for (int i = 0; i < vsize; i++) {
                if (i == idx)continue;
                pq.push(v[i]);
            }
            //cout << v[idx].start << ' ' << v[idx].during << '\n';
            cnt++;
            v.clear();
        }
        else {
            start = pq.top().start;
        }
    }
    return answer / size;
}