#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[1001][1001];
//아래 -> 오른쪽 -> 위로 올리는 과정을 반복한다
vector<int> solution(int n) {
    vector<int> answer;
    int start = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (a[i][j] == 0) {
                //밑으로 쭉 내린다
                int x = i;
                while (true) {
                    if (a[x][j]) {
                        x--;
                        break;
                    }
                    a[x][j] = start++;
                    x++;
                    if (x > n) {
                        x--;
                        break;
                    }
                }
                //오른쪽으로 쭉 간다
                int y = j+1;
                while (true) {
                    if (a[x][y]) {
                        y--;
                        break;
                    }
                    a[x][y] = start++;
                    y++;
                    if (y > x) {
                        y--;
                        break;
                    }
                }
                x--; y--;
          
                //왼쪽위로 쭉올린다
                while (x > 0 && y > 0) {
                    if (a[x][y]) {
                        break;
                    }
                    a[x][y] = start++;
                    x--; y--;
                }

            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(a[i][j]);
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    solution(n);

}