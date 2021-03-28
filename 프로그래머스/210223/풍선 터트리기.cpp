#include <bits/stdc++.h>
using namespace std;
int l[1000002], r[1000002];
// 1~n 까지 i 기준 왼쪽이나 오른쪽에 자신보다 작은 값이 2개면 안됨
int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    l[0] = r[size + 1] = 1000000001;
    for (int i2 = 0; i2 < size; i2++) {
        int i = i2 + 1;
        l[i] = a[i2];
        l[i] = min(l[i], l[i - 1]);
    }
    for (int i2 = size - 1; i2 >= 0; i2--) {
        int i = i2 + 1;
        r[i] = a[i2];
        r[i] = min(r[i], r[i + 1]);
    }
    for (int i = 1; i <= size; i++) {
        int cnt = 0;
        if (a[i - 1] > l[i - 1])cnt++;
        if (a[i - 1] > r[i + 1])cnt++;
        if (cnt < 2)answer++;
    }
    return answer;
}