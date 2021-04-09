// 주사위 윷놀이

#include <stdio.h>

int res = 0;
int map1[20], map2[4] = { 10, 13, 16, 19 }, map3[3] = { 20, 22, 24 }, map4[4] = { 30, 28, 27, 26 }, map5[3] = { 25, 30 ,35 }, map6[1] = { 40 };
int command[10];
struct Point {
	bool end;
	int path, idx;
};
Point p[4];

int move(int& i, int& go) {
	int ret = 0;
	int& path = p[i].path;
	int& idx = p[i].idx;
	idx += go;
	switch (path)
	{
	case 1:
		if (idx == 5)       { path = 2; idx = 0; }
		else if (idx == 10) { path = 3;	idx = 0; }
		else if (idx == 15) { path = 4;	idx = 0; }
		else if (idx == 20) { path = 6; idx = 0; }
		else if (idx > 20)  { p[i].end = true; }
		break;
	case 2:
		if (idx >= 4 && idx < 7) { path = 5; idx = idx - 4; }
		else if (idx == 7) { path = 6; idx = 0; }
		else if (idx > 7)  { p[i].end = true; }
		break;
	case 3:
		if (idx >= 3 && idx < 6) { path = 5; idx = idx - 3; }
		else if (idx == 6) { path = 6; idx = 0; }
		else if (idx > 6)  { p[i].end = true; }
		break;
	case 4:
		if (idx >= 4 && idx < 7) { path = 5; idx = idx - 4; }
		else if (idx == 7) { path = 6; idx = 0; }
		else if (idx > 7) { p[i].end = true; }
		break;
	case 5:
		if (idx == 3) { path = 6; idx = 0; }
		else if (idx > 3) { p[i].end = true; }
		break;
	case 6:
		p[i].end = true;
		break;
	}

	if (p[i].end) return ret;
	for (int index = 0; index < 4; index++) {
		if (index == i || p[index].end) continue;
		if (path == p[index].path && idx == p[index].idx) return -1;
	}

	if		(path == 1) ret = map1[idx];
	else if (path == 2) ret = map2[idx];
	else if (path == 3) ret = map3[idx];
	else if (path == 4) ret = map4[idx];
	else if (path == 5) ret = map5[idx];
	else if (path == 6) ret = map6[idx];
	return ret;
}

void dfs(int cnt, int total) {
	if (cnt == 10) {
		res = res < total ? total : res;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (p[i].end) continue;
		Point tmp = p[i];
		int score = move(i, command[cnt]);
		if (score >= 0) dfs(cnt + 1, total + score);
		p[i] = tmp;
	}
}

int main() {
	for (int i = 1; i <= 19; i++) map1[i] = 2 * i;
	for (int i = 0; i < 10; i++) scanf(" %d", &command[i]);
	for (int i = 0; i < 4; i++) {
		p[i].end = false;
		p[i].path = 1;
		p[i].idx = 0;
	}
	dfs(0, 0);
	printf("%d\n", res);
	return 0;
}