#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[51][51];
pair<int, int> home[101], chi[13];
int dist[101];
int home_idx = 0, chi_idx = 0;
int ans = INT32_MAX;
int calculateDist(pair<int, int> pa, pair<int, int> pb) {
    return abs(pa.first - pb.first) + abs(pa.second - pb.second);
}
void go(int idx, int num) {
    if (num == m) {
        int tans = 0;
        for (int i = 0; i < home_idx; i++) {
            tans += dist[i];
        }
        ans = min(ans, tans);
        return;
    }
    if (idx >= chi_idx)return;
    //치킨집 선정 안하는것
    go(idx + 1, num);
    int origin[101];
    for (int i = 0; i < home_idx; i++) {
        origin[i] = dist[i];
    }
    for (int i = 0; i < home_idx; i++) {
        if (dist[i] == 0 || dist[i] > calculateDist(home[i], chi[idx])) {
            dist[i] = calculateDist(home[i], chi[idx]);
        }
    }
    go(idx + 1, num + 1);
    //백트래킹
    for (int i = 0; i < home_idx; i++) {
        dist[i] = origin[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                home[home_idx].first = i;
                home[home_idx++].second = j;
            }
            if (a[i][j] == 2) {
                chi[chi_idx].first = i;
                chi[chi_idx++].second = j;
            }
        }
    }
    go(0, 0);
    cout << ans << '\n';
}