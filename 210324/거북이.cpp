#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
int T;
// 북 서 남 동
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		// 거북이 최대 500
		// 시작 500,500 부터 ! 
		int x = 500;
		int y = 500;
		int minX = 500, minY = 500;
		int maxX = 500, maxY = 500;
		int dir = 0;
		string cmd; cin >> cmd;
		for (int i = 0; i < cmd.size(); i++) {
			char ch = cmd[i];
			if (ch == 'F') {
				x += dx[dir];
				y += dy[dir];
			}
			else if (ch == 'B') {
				x -= dx[dir];
				y -= dy[dir];
			}
			else if (ch == 'L') {
				dir = (dir + 1) % 4;
			}
			else {
				dir = (dir + 3) % 4;
			}
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
		}
		int res = (maxX - minX) * (maxY - minY);
		cout << res << '\n';
	}
}
