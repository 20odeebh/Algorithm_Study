#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct A {
	int y, d;
	bool operator<(const A& p)const {
		return d > p.d;
	}
};
int d[20001];
bool c[20001];
vector<pair<int, int> > v[20001];
const int INF = 300000;
priority_queue<A> q;
//다익스트라 구현
//단 우선순위 큐로 구현해야 시간초과가 안남
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int start;
	cin >> start;
	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
	}
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	d[start] = 0;
	q.push({ start,0 });
	while (!q.empty()) {
		x = q.top().y;
		q.pop();
		if (c[x])continue;
		c[x] = true;
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			if (d[v[x][i].first] > d[x] + v[x][i].second) {
				d[v[x][i].first] = d[x] + v[x][i].second;
				q.push({ v[x][i].first,d[v[x][i].first] });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << d[i] << '\n';
		}
	}

}