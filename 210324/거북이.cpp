#include <bits/stdc++.h>

using namespace std;

int t, dy[4] = { -1,0,1,0 },dx[4] = { 0,1,0,-1 };

int main() {
	cin >> t;

	while (t--) {
		int y = 0, c = 0, dir = 0, min_x = 0, min_y = 0, max_y = 0, max_x = 0,

		string arr;
		cin >> arr;

		for (int i = 0; i < arr.size(); i++) {
			int ny, nx;
			if (arr[i] == 'F') {
				y = dy[dir%4] + y;
				c = dx[dir%4] + c;
			}
			else if (arr[i] == 'B') {
				y = dy[(dir+2)%4] + y;
				c = dx[(dir+2)%4] + c;
			}
			else if (arr[i] == 'R') dir++;
			else if (arr[i] == 'L') {
				dir--;
				if (dir < 0) dir += 4;
			}

			if (max_x < c) max_x = c;
			if (max_y < y) max_y = y;
			if (min_x > c) min_x = c;
			if (min_y > y) min_y = y;
		}
		cout << ((max_y - min_y)* (max_x - min_x)) << "\n";
	}
}
