#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//방향 : 0, 1, 2, 3 : 북 동 남 서
//+1 : 오른쪽 90도 회전, +3 : 왼쪽 90도 회전
pair<int, int> fw[4][2] = {
	{ { -1, 0 },{ 1, 0 } },
	{ { 0, 1 },{ 0, -1 } },
	{ { 1, 0 },{ -1, 0 } },
	{ { 0, -1 },{ 0, 1 } }
};
int dir = 0;
#define MAX_SIZE 501
int dirRow[] = { 1, 0, -1,0 };
int dirCol[] = { 0, 1, 0, -1 };
int sim(const string& str)
{
	pair<int, int> cur = { 0 , 0 };
	int max_row = 0, max_col = 0;
	int min_row = 0, min_col = 0;
	auto size = str.length();
	auto& row = cur.first;
	auto& col = cur.second;
	for (int i = 0; i < size; i++) {
		switch (str[i]) {
		case 'F':
			row = row + fw[dir][0].first;
			col = col + fw[dir][0].second;
			break;
		case 'B':
			row = row + fw[dir][1].first;
			col = col + fw[dir][1].second;
			break;
		case 'L':
			dir = (dir + 3) % 4;
			break;
		case 'R':
			dir = (dir + 1) % 4;
			break;
		}
		min_row = min(row, min_row);
		min_col = min(col, min_col);
		max_row = max(row, max_row);
		max_col = max(col, max_col);
	}
	printf("%d\n", (max_row - min_row) * (max_col - min_col));
	return 1;
}
int main()
{
	int tc;
	cin >> tc;
	string str;
	for (int t = 0; t < tc; t++) {
		cin >> str;
		sim(str);
	}
	return 0;
}