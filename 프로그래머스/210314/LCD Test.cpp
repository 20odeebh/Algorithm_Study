#include<bits/stdc++.h>
//정답 참조
#define zero '-'
#define one '|'

#define segments 7
#define rep(i,a,b) for(int i=a;i<b;i++)
const int dx[] = { 0, 1 }, dy[] = { 1, 0 };
const int MAXR = 2 * 10 + 10 + 1, MAXC = ((10 + 2) * 10) + 10 + 1;
using namespace std;

int s;
char a[MAXR][MAXC];
int stD[segments] = { 0, 1, 1, 0, 1, 1, 0 };
pair<int, int> stP[segments];
const vector<int> number[] = {
    {0, 1, 2, 4, 5, 6},
    {1, 4},
    {0, 1, 3, 5, 6},
    {0, 1, 3, 4, 6},
    {1, 2, 3, 4},
    {0, 2, 3, 4, 6},
    {0, 2, 3, 4, 5, 6},
    {0, 1, 4},
    {0, 1, 2, 3, 4, 5, 6},
    {0, 1, 2, 3, 4, 6}
};
void simulate(int sx, int sy, int x) {
    stP[0] = { sx, sy }, stP[1] = { sx, sy + s + 1 }, stP[2] = { sx, sy }, stP[3] = { sx + s + 1, sy }, stP[4] = { sx + s + 1, sy + s + 1 }, stP[5] = { sx + s + 1, sy }, stP[6] = { sx + 2 * s + 2, sy };
    rep(i, 0, number[x].size()) {
        int segNum = number[x][i];
        rep(i, 1, s + 1) {
            if (stD[segNum] == 0) {
                a[stP[segNum].first + dx[stD[segNum]] * i][stP[segNum].second + dy[stD[segNum]] * i] = zero;
            }
            else {
                a[stP[segNum].first + dx[stD[segNum]] * i][stP[segNum].second + dy[stD[segNum]] * i] = one;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> s >> str;
    int sx = 0, sy = 0;
    rep(i, 0, MAXR) rep(j, 0, MAXC) a[i][j] = '.';
    rep(i, 0, str.size()) {
        simulate(sx, sy, stoi(str.substr(i, 1)));
        sy += (s + 2);
        sy += 1; // 숫자사이의 공백
    }
    rep(i, 0, sx + 2 * s + 3) {
        rep(j, 0, sy) { // 실수 : sy대신 sy+s로 사용함.(다음 문자가 없음에도 불구하고)
            if (a[i][j] == '.') cout << " ";
            else cout << a[i][j];
        }cout << '\n';
    }
    return 0;
}