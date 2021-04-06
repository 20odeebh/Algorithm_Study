#include <iostream>
#include <queue>

using namespace std;

const int WALL = -1;
const int EMPTY = -2;

int n, m, fuel, taxi_y, taxi_x board[20][20], dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

struct TAXI {
	int pos, dis;
};

struct CUSTOMER {
	int start, end;
};

CUSTOMER customer[400];

int find_customer() {
	queue<TAXI> q;
	bool vis[20][20] = { false };

	TAXI cur = { taxi_y * 100 + taxi_x,0 };
	q.push(cur);
	vis[taxi_y][taxi_x] = true;

	int candi_dis = -1;
	int candi[400] = { 0 };
	int candi_cnt = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		int y = cur.pos / 100;
		int x = cur.pos % 100;
		
		if (candi_dis != -1 && cur.dis > candi_dis) break;

		if (board[y][x] >= 0) {
			candi[candi_cnt++] = board[y][x];
			candi_dis = cur.dis;
		}
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == WALL || vis[ny][nx] == true) continue;
			TAXI next = { ny * 100 + nx,cur.dis + 1 };
			q.push(next);
			vis[ny][nx] = true;
		}
	}
  
	int ret = -1;
	int candiMin = 987654321;
  
	for (int i = 0; i < candi_cnt; i++) {
		if (candiMin > customer[candi[i]].start) {
			candiMin = customer[candi[i]].start;
			ret = candi[i];
		}
	}
  
	if (candi_dis > fuel)return -1;
	fuel -= candi_dis;
	taxi_y = customer[ret].start / 100;
	taxi_x = customer[ret].start % 100;
	board[taxi_y][taxi_x] = EMPTY;
	return ret;
}

bool move(int target) {
	queue<TAXI> q;
	bool vis[20][20] = { false };

	TAXI cur = { taxi_y * 100 + taxi_x,0 };
	q.push(cur);
	vis[taxi_y][taxi_x] = true;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.dis > fuel)return false;
		if (cur.pos == customer[target].end) {
			fuel += cur.dis;
			taxi_y = customer[target].end / 100;
			taxi_x = customer[target].end % 100;			
			return true;
		}
		
		int y = cur.pos / 100;
		int x = cur.pos % 100;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == WALL || vis[ny][nx] == true) continue;
			TAXI next = { ny * 100 + nx,cur.dis + 1 };
			q.push(next);
			vis[ny][nx] = true;
		}
	}
	return false;	
}

int solve() {
	for (int i = 0; i < m; i++) {
		int target = find_customer();
		if (target == -1) return -1;
		bool flag = move(target);
		if (flag == false) return -1;
	}
	return fuel;
}

int main() {
	cin >> n >> m >> fuel;
  
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			board[i][j] -= 2;
		}		
	}
  
	cin >> taxi_y >> taxi_x;
	--taxi_y;
  --taxi_x;
  
	for (int i = 0; i < m; i++) {
		int sy, sx, fy, fx;
		cin >> sy >> sx >> fy >> fx;
		--sy;
    --sx; 
    --fy;
    --fx;
		customer[i] = { sy * 100 + sx,fy * 100 + fx };
		board[sy][sx] = i;
	}
	cout << solve();
}
