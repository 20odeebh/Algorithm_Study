#include <bits/stdc++.h>
using namespace std;
int a[6][3];
pair<int, int> p[15];
// x와 y의 대결에서 승 0,무, 패 에 대한 모든 경우의수를
// dfs + 백트래킹으로 완전탐색한다.
bool ansFlag = false;
void go(int idx) {
    if (ansFlag)return;
    if (idx == 15) {
        bool temp = true;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j]) {
                    temp = false;
                    break;
                }
            }
            if (temp == false)break;
        }
        if (temp)ansFlag = true;
        return;
    }
    int x = p[idx].first, y = p[idx].second;
    for (int i = 0; i < 3; i++) {
        if (a[x][i] && a[y][2 - i]) {
            a[x][i]--;
            a[y][2 - i]--;
            go(idx + 1);
            a[x][i]++;
            a[y][2 - i]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 4;
    int idx = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            p[idx].first = i;
            p[idx++].second = j;
        }
    }
    while (T--) {
        int ans = 1;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }
        ansFlag = false;
        go(0);
        if (ansFlag)cout << "1 ";
        else cout << "0 ";

    }
}