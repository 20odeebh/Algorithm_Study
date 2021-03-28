#include <bits/stdc++.h>
using namespace std;
//다익스트라
//방향까지 비용에 계산해준다 
//0 오른쪽, 1 아래쪽, 2 왼쪽, 3위쪽
int d[25][25][4];
const int MAX = 100000000;
struct pos {
    int x, y, dir, cost;
    bool operator<(const pos& p)const {
        return cost > p.cost;
    }
};
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
priority_queue<pos> pq;
int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                d[i][j][k] = MAX;
            }
        }
    }
    d[0][0][0] = d[0][0][1] = 0;
    pq.push({ 0,0,0,0 });
    pq.push({ 0,0,1,0 });
    while (!pq.empty()) {
        int x = pq.top().x, y = pq.top().y, dir = pq.top().dir, cost = pq.top().cost;
        pq.pop();
        if (cost > d[x][y][dir])continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
            if (board[nx][ny] == 1)continue;
            int now_cost = 100;
            if (dir != i)now_cost += 500;
            if (d[nx][ny][i] > d[x][y][dir] + now_cost) {
                d[nx][ny][i] = d[x][y][dir] + now_cost;
                pq.push({ nx,ny,i,d[nx][ny][i] });
            }
        }
    }

    answer = d[n - 1][n - 1][0];
    for (int i = 1; i < 4; i++) {
        answer = min(answer, d[n - 1][n - 1][i]);
    }
    return answer;
}
