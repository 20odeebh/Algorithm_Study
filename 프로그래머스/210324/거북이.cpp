#include <bits/stdc++.h>
using namespace std;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//방향은 dx나 dy로 설정후 그대로 구현
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int x = 0, y = 0, dir = 0;
        int minx = 0, miny = 0, maxx = 0, maxy = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'F') {
                x += dx[dir]; y += dy[dir];

            }
            else if (s[i] == 'B') {
                x -= dx[dir]; y -= dy[dir];
            }
            else if (s[i] == 'L') {
                dir--;
                if (dir < 0)dir += 4;
            }
            else {
                dir++;
                if (dir > 3)dir -= 4;
            }
            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
        }
        cout << (maxx - minx) * (maxy - miny) << '\n';
    }
}