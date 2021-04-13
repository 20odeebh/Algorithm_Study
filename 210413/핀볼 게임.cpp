#include <stdio.h> 
#include <utility>
#include <algorithm>

 using namespace std;

 int n, res;
 int arr[101][101];
 int dy[4] = { 0, 0, 1, -1 };
 int dx[4] = { 1, -1, 0, 0 };
 int block[6][4] = { {0, 0, 0, 0},
                     {1, 3, 0, 2},
                     {1, 2, 3, 0},
                     {2, 0, 3, 1},
                     {3, 0, 1, 2},
                     {1, 0, 3, 2} };
 pair<int, int> warmhole[11][2];

 int game(int y, int x, int d) {
     int sy = y, sx = x;
     int ny, nx, cnt = 0, next;
     while (true) {
         ny = y + dy[d];
         nx = x + dx[d];
         if (ny < 0 || ny == n || nx < 0 || nx == n) {
             cnt <<= 1;
             cnt |= 1;
             return cnt;
         }
         if ((ny == sy && nx == sx) || arr[ny][nx] == -1) return cnt;
         next = arr[ny][nx];
         if (next == 0) {
             y = ny;
             x = nx;
             continue;
         }
         else if (next >= 1 && next <= 5) {
             y = ny;
             x = nx;
             d = block[next][d];
             cnt++;
             continue;
         }
         else {
             if (ny == warmhole[next][0].first && nx == warmhole[next][0].second) {
                 y = warmhole[next][1].first;
                 x = warmhole[next][1].second;
             }
             else {
                 y = warmhole[next][0].first;
                 x = warmhole[next][0].second;
             }
         }
     }
 }

 int main() {
     //freopen("sample_input.txt", "r", stdin);
     int test_case, val;
	 scanf("%d", &test_case);
     for (int tc = 1; tc <= test_case; tc++) {
		 scanf(" %d", &n);
         res = 0;
         int warm_idx[11] = { 0, };
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
				 scanf(" %d", &arr[i][j]);
                 if (arr[i][j] >= 6 && arr[i][j] <= 10) 
					 warmhole[arr[i][j]][warm_idx[arr[i][j]]++] = make_pair(i, j);
             }
         }
         for (int i = 0; i < n; i++) {
			 for (int j = 0; j < n; j++) {
				 if (arr[i][j]) continue;
				 for (int k = 0; k < 4; k++) {
					 val = game(i, j, k);
					 res = max(res, val);
				 }
			 }
         }
		 printf("#%d %d\n", tc, res);
     }
     return 0;
 }