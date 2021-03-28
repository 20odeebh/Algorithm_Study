#include <bits/stdc++.h>
using namespace std;
string s[12];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
// dfs로 터트리면서 내려준다
bool check[12][6];
int totalCnt = 0;
void dfs(int x, int y, char c) {
    check[x][y] = true;
    totalCnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)continue;
        if (check[nx][ny] == false && s[nx][ny] == c) {
            dfs(nx, ny, c);
        }
    }
}
void dfs2(int x, int y, int c) {
    s[x][y] = '.';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)continue;
        if (s[nx][ny] == c) {
            dfs2(nx, ny, c);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 12; i++) {
        cin >> s[i];
    }
    int ans = 0;
    while (true) {
        int cnt = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                check[i][j] = false;
            }
        }
        //터트리기
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (s[i][j] != '.') {
                    if (check[i][j] == false) {
                        totalCnt = 0;
                        dfs(i, j, s[i][j]);
                        if (totalCnt >= 4) {
                            dfs2(i, j, s[i][j]);
                            cnt++;
                        }
                    }
                }
            }
        }
        if (cnt == 0) {
            cout << ans;
            return 0;
        }
        ans++;
        //내리기 
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (s[i][j] != '.') {
                    int i2 = i + 1;
                    while (i2 < 12) {
                        if (s[i2][j] == '.') {
                            s[i2][j] = s[i2 - 1][j];
                            s[i2 - 1][j] = '.';
                            i2++;
                        }
                        else break;
                    }
                }
            }
        }
    }
}