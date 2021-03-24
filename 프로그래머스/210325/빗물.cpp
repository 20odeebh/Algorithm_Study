#include <bits/stdc++.h>
using namespace std;
int a[501][501];
// 배열 그대로 만들어서 왼쪽 끝과 오른쪽 끝에 벽이 있는지 확인
// 둘다 있으면 물을 2로 담아주고 최종적으로 2의 갯수를 센다.
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int j2 = n - t;
        for (int j = n - 1; j >= j2; j--) {
            a[j][i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        bool leftWall = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                int j2 = j + 1;
                bool rightWall = false;
                while (j2 < m) {
                    if (a[i][j2] == 1) {
                        rightWall = true;
                        break;
                    }
                    else {
                        j2++;
                    }
                }
                if (leftWall && rightWall) {
                    for (int k = j; k < j2; k++) {
                        a[i][k] = 2;
                    }
                }
                j = j2 - 1;
            }
            else {
                leftWall = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}