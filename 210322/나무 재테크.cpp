#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rs,n, m, k, a[10][10], s[10][10], dy[8] = { -1,-1,-1,0,0,1,1 ,1}, dx[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> v[10][10];

void spring() {
	vector<int> temp;
	int die_tree = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size() == 0) continue;
			sort(v[i][j].begin(), v[i][j].end());
			for (int tree : v[i][j]) {
				if (s[i][j] >= tree) {
					s[i][j] -= tree;
					temp.push_back(tree + 1);
				}
				else {
					die_tree += tree/2;

				}
			}
			s[i][j] += die_tree;
			v[i][j].empty();
			v[i][j] = temp;
			die_tree = 0;
			temp.clear();
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int tree : v[i][j]) {
				if (tree % 5 == 0) {
					for (int a = 0; a < 8; a++) {
						int ny = i + dy[a];
						int nx = j + dx[a];
						if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
						v[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			s[i][j] += a[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> k;
  
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			s[i][j] = 5;
		}
	}
  
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x - 1][y - 1].push_back(z);
	}
  
	while (k--) {
		spring();
		fall();
		winter();
	}
  
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			rs += v[i][j].size();
		}
	}
  
	cout << rs;
}
