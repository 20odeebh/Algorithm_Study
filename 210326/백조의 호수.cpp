#include <bits/stdc++.h>

using namespace std;

int r, c, dy[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
vector<string> arr;
bool isFind, ch[1501][1501];
pair<int, int> swan;
queue<pair<int, int>> sq, wq, tmpSQ, tmpWQ;

void swanBfs() {
	while (!sq.empty()) {
		int x = sq.front().first;
		int y = sq.front().second;
		sq.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dy[k][0];
			int ny = y + dy[k][1];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c || ch[nx][ny]) continue;
			ch[nx][ny] = true;
			
			if (arr[nx][ny] == 'X') tmpSQ.push({ nx,ny });
			else if (arr[nx][ny] == '.') sq.push({ nx,ny });
			else if (arr[nx][ny] == 'L') {
				isFind = true;
				break;
			}
	
		}
	}
}

void water() {
	while (!wq.empty()) {
		int x = wq.front().first;
		int y = wq.front().second;
		wq.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dy[k][0];
			int ny = y + dy[k][1];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			
			if (arr[nx][ny] == 'X') {
				arr[nx][ny] = '.';
				tmpWQ.push({ nx,ny });
			}
		}
	}
}

int meet() {
	int day = 0;
	while (!isFind) {
		swanBfs();
		if (isFind) break;
		water();
		
		sq = tmpSQ;
		wq = tmpWQ;
		
		while (!tmpSQ.empty()) {
		tmpSQ.pop();
		}
		while (!tmpWQ.empty()) {
		tmpWQ.pop();
		}
		day++;
	}
	return day;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		arr.push_back(str);
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'L') {
				swan.first = i;
				swan.second = j;
			}
			
			if (arr[i][j] != 'X') {
				wq.push({ i,j });
			}
		}
	}
	
	ch[swan.first][swan.second] = true;
	sq.push(swan);
	cout << meet() << "\n";
}