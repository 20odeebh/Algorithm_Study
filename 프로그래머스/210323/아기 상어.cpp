#include <bits/stdc++.h>
using namespace std;
int a[21][21];
const int MAX = 420;
int n;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int dist[21][21];
queue<pair<int, int>> q;
int nx = 0, ny = 0, size1 = 2, countEat = 0;
//BFS로 먹을 상어를 찾은후 계산
void BFS(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = MAX;
        }
    }
    dist[x][y] = 0;
    q.push({ x,y });
    while (!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = nx + dx[i], nexty = ny + dy[i];
            if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= n)continue;
            if (a[nextx][nexty] <= size1) {
                if (dist[nextx][nexty] > dist[nx][ny] + 1) {
                    dist[nextx][nexty] = dist[nx][ny] + 1;
                    q.push({ nextx,nexty });
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                nx = i;
                ny = j;
            }
        }
    }
    int ans = 0;
    while (true) {
        int MIN = MAX;
        int x = 0, y = 0;
        BFS(nx, ny);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == nx && j == ny)continue;
                if (a[i][j]>0 && size1 > a[i][j]) {
                    if (MIN > dist[i][j]) {
                        MIN = dist[i][j];
                        x = i; y = j;
                    }
                }
            }
        }
        if (MIN == MAX) {
            cout << ans;
            return 0;
        }
        a[nx][ny] = 0;
        countEat++;
        if (countEat == size1) {
            size1++;
            countEat = 0;
        }
        ans += MIN;
        nx = x; ny = y;
        a[x][y] = 9;
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < n; j++) {
        //        cout << a[i][j] << ' ';
        //    }
        //    cout << '\n';
        //}
        //cout << ans << ' ' << size1 << ' ' << countEat << '\n';
    }
}