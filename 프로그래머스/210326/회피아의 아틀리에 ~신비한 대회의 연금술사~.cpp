#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
//정답 참조
struct state {
    int eff;
    char ele;

    state() { }
    state(int _eff, char _ele) : eff(_eff), ele(_ele) { }
};

int n, ans;
int efficacy[10][4][4][4];
char element[10][4][4][4];
bool visited[10];

vector<vector<state>> map(5, vector<state>(5));

// 입력 배열을 90도로 3번 회전하여 각각을 저장하는 함수
void rotateArr(int type, int dir) {
    // 90 도 회전
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            efficacy[type][dir][i][j] = efficacy[type][dir - 1][3 - j][i];
            element[type][dir][i][j] = element[type][dir - 1][3 - j][i];
        }
    }
}

// 폭탄의 최대 품질을 구하는 함수
int getQuality(vector<vector<state>> v) {
    int r = 0;
    int b = 0;
    int g = 0;
    int y = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            switch (v[i][j].ele) {
            case 'R':
                r += v[i][j].eff;
                break;
            case 'B':
                b += v[i][j].eff;
                break;
            case 'G':
                g += v[i][j].eff;
                break;
            case 'Y':
                y += v[i][j].eff;
                break;
            default:
                break;
            }
        }
    }

    return 7 * r + 5 * b + 3 * g + 2 * y;
}

// 가마에 재료의 종류, 방향에 따라 재료를 놓는 함수
vector<vector<state>> putMaterial(vector<vector<state>> v, int row, int col, int type, int dir) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // 효능
            v[row + i][col + j].eff += efficacy[type][dir][i][j];

            if (v[row + i][col + j].eff < 0)
                v[row + i][col + j].eff = 0;
            else if (v[row + i][col + j].eff > 9)
                v[row + i][col + j].eff = 9;

            // 원소
            if (element[type][dir][i][j] != 'W') {
                v[row + i][col + j].ele = element[type][dir][i][j];
            }
        }
    }

    return v;
}

void dfs(vector<vector<state>> v, int cnt) {
    // 재료 3개를 모두 선택한 경우
    if (cnt == 3) {
        ans = max(ans, getQuality(v));
        return;
    }

    // dfs
    for (int t = 0; t < n; t++) {
        if (!visited[t]) {
            visited[t] = true;

            // (0,0) (0,1) (1,0) (1,1)
            // 4 좌표에 대해 재료 배치 가능
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    // 원래방향, 시계방향, 반시계방향
                    for (int d = 0; d < 4; d++) {
                        vector<vector<state>> tmp = putMaterial(v, i, j, t, d);

                        dfs(tmp, cnt + 1);
                    }
                }
            }

            visited[t] = false;
        }
    }
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int t = 0; t < n; t++) {
        // 효능 입력
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> efficacy[t][0][i][j];
            }
        }

        // 원소 입력
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> element[t][0][i][j];
            }
        }

        // 입력받은 효능, 원소 회전
        for (int d = 1; d <= 3; d++) {
            rotateArr(t, d);
        }
    }

    // 초기화
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = state(0, 'W');
        }
    }
    memset(visited, false, sizeof(visited));
    ans = -INF;

    dfs(map, 0);

    cout << ans << "\n";

    return 0;
}