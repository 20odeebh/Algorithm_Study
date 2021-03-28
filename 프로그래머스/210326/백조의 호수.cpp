#include <bits/stdc++.h>
using namespace std;
//최초 거꾸로 BFS하여 얼음이 녹는 시간을 한번에 계산
//이후 다익스트라를 통해 가장 가까운 길을 찾는다.
//얼음이 녹는 메모리는 dist1에, 가장 가까운 길을 저장한 메모리는 dist2에 저장
string s[1500];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int dist1[1501][1501], dist2[1501][1501];
bool check[1501][1501];
queue < pair<int, int>> q;
const int MAX = 1500 * 1501;
struct A {
    int x, y, dist;
    bool operator<(const A& p)const {
        return dist > p.dist;
    }
};
priority_queue<A> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int sx = -1, sy = -1, ex = 0, ey = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            dist2[i][j] = MAX;
            if (s[i][j] == 'L') {
                if (sx == -1) {
                    sx = i; sy = j;
                }
                else {
                    ex = i; ey = j;
                }
                s[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                bool water = false;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                    if (s[nx][ny] == '.') {
                        water = true;
                        break;
                    }
                }
                if (water) {
                    q.push({ i,j });
                    dist1[i][j] = 1;
                }
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (s[nx][ny] == 'X' && dist1[nx][ny]==0) {
                dist1[nx][ny] = dist1[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }
    dist2[sx][sy] = 0;
    pq.push({ sx,sy,0 });
    while (!pq.empty()) {
        int x = pq.top().x, y = pq.top().y;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (s[nx][ny] == 'X') {
                if (check[nx][ny] == false) {
                    check[nx][ny] = true;
                    dist2[nx][ny] = max(dist1[nx][ny], dist2[x][y]);
                    pq.push({ nx,ny,dist2[nx][ny] });
                }
            }
            else {
                if (dist2[nx][ny] > dist2[x][y]) {
                    dist2[nx][ny] = dist2[x][y];
                    pq.push({ nx,ny,dist2[nx][ny] });
                }
            }
        }
    }
    cout << dist2[ex][ey] << '\n';
}