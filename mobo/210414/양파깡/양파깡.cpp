#include <iostream>
#include <vector>
int N, M;
int pane[31][31];
int visit[31][31];
using namespace std;
void read() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &pane[i][j]);
		}
	}
}
int cal(int x1, int y1, int x2, int y2) {
	int ret = 0;
	for (int i = x1; i <= x2; i++) {
		ret += pane[i][y1];
		ret += pane[i][y2];
	}
	for (int j = y1 + 1; j <= y2 - 1; j++) {
		ret += pane[x1][j];
		ret += pane[x2][j];
	}
	return ret;
}
bool hasVisit(int x1, int y1, int x2, int y2) {
	for (int i = x1; i <= x2; i++) {
		if (visit[i][y1] == 1 || visit[i][y2] == 1) {
			return true;
		}
	}
	for (int j = y1 + 1; j <= y2 - 1; j++) {
		if (visit[x1][j] == 1 || visit[x2][j] == 1) {
			return true;
		}
	}
	return false;
}
pair<pair<int, int>, pair<int, int>> getTaste(int*ret) {//좌표 overflow는 생각 안해도됨
	*ret = -99999999;
	pair<int, int> pos;
	pair<int, int> val;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < N - 2; j++) {
			for (int k = i + 2; k < N; k++) {
				for (int l = j + 2; l < N; l++) {
					if (hasVisit(i, j, k, l)) {
						continue;
					}
					int tmp = cal(i, j, k, l);
					if (*ret < tmp) {
						*ret = tmp;
						pos = make_pair(i, j);
						val = make_pair(k, l);
					}
				}
			}
		}
	}

	return make_pair(pos, val);



}
void setVisit(pair<pair<int, int>, pair<int, int>>node) {
	int x = node.first.first;
	int y = node.first.second;
	int a = node.second.first;
	int b = node.second.second;
	for (int i = x; i <= a; i++) {
		visit[i][y] = 1;
		visit[i][b] = 1;
	}
	for (int i = y; i <= b; i++) {
		visit[x][i] = 1;
		visit[a][i] = 1;
	}
}
int play() {
	vector < pair<int, pair<pair<int, int>, pair<int, int>>>> cookie;
	int x = 0, y = 0;
	int h = N, w = N;
	for (int i = 0; i < M; i++) {
		int ret = 0;
		pair<pair<int, int>, pair<int, int>>node = getTaste(&ret);
		setVisit(node);
		if (ret == -99999999) {
			cout << 0;
			return 0;
		}
		cookie.push_back(make_pair(ret, node));
	}

	vector < pair<int, pair<pair<int, int>, pair<int, int>>>>::iterator itr = cookie.begin();
	for (; itr != cookie.end(); itr++) {
		cout << (*itr).first << " " << (*itr).second.first.first + 1 << " " << (*itr).second.first.second + 1 << " " << (*itr).second.second.first + 1 << " " << (*itr).second.second.second + 1 << endl;
	}
	return 1;

}



int main()
{
	read();
	play();

}
