#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
using pii = pair<int, int>;
int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };
int r, c;
vector<pii> duck_pos;
queue<pii> nxt_duck_pos;
vector<pii> ice_melting(vector<vector<char>>& v, vector<pii>& points) {
	vector<pii> nxt_melting;

	for (auto point : points) {
		for (int i = 0; i < 4; i++) {
			int nr = point.first + dr[i];
			int nc = point.second + dc[i];
			if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
			if (v[nr][nc] == 'X') {
				v[nr][nc] = '.';
				nxt_melting.push_back({ nr,nc });
			}
		}
	}
	return nxt_melting;
}

bool duck_meet_check(vector<vector<char>>& v, queue<pii>& q, vector<vector<bool>>& vis) {
	queue<pii> tmp_q;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first == duck_pos[1].first && cur.second == duck_pos[1].second)
			return true;
		for (int i = 0; i < 4; i++) {
			int nr = cur.first + dr[i];
			int nc = cur.second + dc[i];
			if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
			if (vis[nr][nc]) continue;
			if (v[nr][nc] == 'X') {
				tmp_q.push({ nr,nc });
				vis[nr][nc] = 1;
				continue;
			}
			q.push({ nr,nc });
			vis[nr][nc] = 1;
		}
	}
	q = tmp_q;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> r >> c;
	vector<vector<char>> v;
	vector<pii> water;
	vector<vector<bool>> vis;
	for (int i = 0; i < r; i++) {
		vector<bool> vis_e(c);
		vis.push_back(vis_e);
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		vector<char> v_e(s.size());
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'L') duck_pos.push_back({ i,j });
			if (s[j] != 'X') water.push_back({ i,j });
			v_e[j] = s[j];
		}
		v.push_back(v_e);
	}
	nxt_duck_pos.push({ duck_pos[0].first,duck_pos[0].second });
	vis[duck_pos[0].first][duck_pos[0].second] = 1;

	while (!duck_meet_check(v, nxt_duck_pos, vis))
	{
		water = ice_melting(v, water);
		ans++;
	}

	cout << ans;
	return 0;
}