#include <vector>
#include <iostream>

using namespace std;

struct POSI {
	int y, x;
};

int n, m,rs=987654321; 
int a[50][50];
vector<POSI> home,chicken,real_ch;

void dfs(int cur) {
	if (real_ch.size() == m) {
		int ret = 0;
		for (int i = 0; i < home.size(); i++) {
			int mind = 987654321;
			for (int j = 0; j < real_ch.size(); j++) {
				int d = abs(home[i].y - real_ch[j].y) + abs(home[i].x - real_ch[j].x);
				if (mind > d)mind = d;
			}
			ret += mind;
		}
		if (rs > ret)rs = ret;
		return;
	}
	for (int i = cur; i < chicken.size(); i++) {
		real_ch.push_back(chicken[i]);
		dfs(i + 1);
		real_ch.pop_back();
	}
}

int main() {
	POSI pos;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				pos.y = i;
				pos.x = j;
				home.push_back(pos);
			}
			if (a[i][j] == 2) {
				pos.y = i;
				pos.x = j;
				chicken.push_back(pos);
			}
		}
	}
	rs = 0x7fffffff;
	dfs(0);
	cout << rs;
}
