#include <bits/stdc++.h>
using namespace std;
//입력시간을 초단위로 나타내어 가장 빨리 시작하는 시간대로 
//우선순위 큐에 넣는다.
//여기서 우선순위큐의 top은 가장 일찍끝나는 시간대로 정렬하며
//큐에 넣을 시작시간과 큐 top에 있는 끝나는 시간차가 1초 이상이면 빼주고
//큐 사이즈중 최댓값을 정답으로 출력


//시간을 초*1000 단위로 나타낼 구조체
struct sec {
    int start, end;
    //끝나는 시간이 빠른순으로 사용하기 위함
    bool operator < (const sec& p)const {
        return end > p.end;
    }
};
bool cmp(sec A, sec B) {
    return A.start < B.start;
}
priority_queue<sec> pq;
sec a[2001];
int solution(vector<string> lines) {
    int answer = 0;
    int size = lines.size();
    for (int i = 0; i < size; i++) {
        //11~12 , 14~15 , 17~18 , 20~22, 24~
        int hour = 0, minute = 0, second = 0,total=0;
        hour = stoi(lines[i].substr(11, 2));
        minute = stoi(lines[i].substr(14, 2));
        second = stoi(lines[i].substr(17, 2));
        total += (hour * 3600 + minute * 60 + second)*1000;
        total += stoi(lines[i].substr(20, 3));
        a[i].end = total;
        int duration = 0,cnt=0;
        for (int j = 24; j < lines[i].size(); j++) {
            if (lines[i][j] >= '0' && lines[i][j] <= '9') {
                duration *= 10;
                duration += lines[i][j] - '0';
                cnt++;
            }
        }
        for (int i = cnt + 1; i <= 4; i++)duration *= 10;
        a[i].start = a[i].end - duration +1;
    }
    sort(a, a + size,cmp);
    for (int i = 0; i < size; i++) {
        while (!pq.empty()) {
            int dif = a[i].start - pq.top().end;
            if (dif > 999)pq.pop();
            else break;
        }
        pq.push(a[i]);
        
        answer = max(answer, (int)pq.size());
    }

    return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pq.push({ 1,1 });
    pq.push({ 1,3 });
    pq.push({ 1,4 });
    cout << pq.top().end << '\n';

    solution({ "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" });
}