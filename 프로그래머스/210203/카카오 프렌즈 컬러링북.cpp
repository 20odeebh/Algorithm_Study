#include <vector>
#include <algorithm>
using namespace std;
int temp;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool check[101][101];
int nn, mm;
vector<vector<int>> p;
//dfs로 풀음.
void dfs(int x, int y) {
    check[x][y] = true;
    temp++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= nn || ny < 0 || ny >= mm)continue;
        if (p[nx][ny] == p[x][y]) {
            if (check[nx][ny] == false) {
                dfs(nx, ny);
            }
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    nn = m;
    mm = n;
    p = picture;
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; j++) {
            check[i][j] = false;
        }
    }
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; j++) {
            if (picture[i][j] && check[i][j] == false) {
                temp = 0;
                dfs(i, j);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, temp);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}