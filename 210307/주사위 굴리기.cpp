#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int n, m; 
int x, y; 
int k;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct Dice {
	deque<int> row;
	deque<int> col;
	pii pos;
};

bool dice_roll(Dice &dice, int k) {
	int nx = dice.pos.first + dx[k - 1];
	int ny = dice.pos.second + dy[k - 1];
	if (nx<0 || ny<0 || nx>=n || ny>=m) return false;
	dice.pos = { nx,ny };

	switch (k) {
	case 1:
	{
		dice.row.push_front(dice.row.back());
		dice.row.pop_back();
		dice.col[1] = dice.row[1];
		dice.col[3] = dice.row[3];
		break;
	}
	case 2:
	{
		dice.row.push_back(dice.row.front());
		dice.row.pop_front();
		dice.col[1] = dice.row[1];
		dice.col[3] = dice.row[3];
		break;
	}
	case 3: 
	{
		dice.col.push_back(dice.col.front());
		dice.col.pop_front();
		dice.row[1] = dice.col[1];
		dice.row[3] = dice.col[3];
		break;
	}
	case 4:
	{
		dice.col.push_front(dice.col.back());
		dice.col.pop_back();
		dice.row[1] = dice.col[1];
		dice.row[3] = dice.col[3];
		break;
	}
	}
	return true;
}

void change_value(Dice& dice, vector<vector<int>>& v) {
	int x = dice.pos.first;
	int y = dice.pos.second;
	if (v[x][y] == 0) {
		v[x][y] = dice.col[3];
	}
	else {
		dice.col[3] = v[x][y];
		dice.row[3] = v[x][y];
		v[x][y] = 0;
	}
}

int main() {
	cin >> n >> m >> x >> y >> k;
	Dice dice;
	dice.row.assign(4, 0);
	dice.col.assign(4, 0);
	dice.pos = { x,y };

	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		vector<int> elem(m);
		for (int j = 0; j < m; j++) {
			cin >> elem[j];
		}
		v.push_back(elem);
	}

	for (int i = 0; i < k; i++) {
		int cmd;
		cin >> cmd;
		if (dice_roll(dice, cmd)) {
			change_value(dice, v);
			cout << dice.col[1] << '\n';
		}
	}
	return 0;
}