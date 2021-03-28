#include <bits/stdc++.h>
using namespace std;
string total;
//숫자와 진법
//total에 m*t 길이 이상의 말하는 수를 저장
//정답에 m을 간격으로 추가해준다.
void change(int n, int k) {
    string temp = "";
    while (n) {
        int mod = n % k;
        char c;
        if (mod > 9) c = 'A' + (mod - 10);
        else c = (mod + '0');
        temp += c;
        n /= k;
    }
    for (int i = temp.size() - 1; i >= 0; i--)total += temp[i];
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    total = "0";
    int start = 1;
    int tm = t * m;
    while (true) {
        change(start, n);
        if (total.size() > tm)break;
        start++;
    }
    int cnt = 0;
    for (int i = p - 1; i < total.size(); i += m) {
        answer += total[i];
        cnt++;
        if (cnt == t)break;
    }
    return answer;
}