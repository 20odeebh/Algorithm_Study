#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int n,c0,c1;
vector<vector<int>> a;
//size 크기의 배열을 탐색해 모두 같으면 cnt 증가
//다르면 4방향으로 분할시켜서 탐색
void go(int x,int y,int size) {
	if (size == 1) {
		if (a[x][y] == 0)c0++;
		else c1++;
		return;
	}
	int i2 = x + size, j2 = y + size;
	bool flag = true;
	for (int i = x; i < i2; i++) {
		for (int j = y; j < j2; j++) {
			if (a[x][y] != a[i][j]) {
				flag = false;
				break;
			}
		}
	}
	if (flag == false) {
		int size2 = size / 2;
		go(x, y, size2);
		go(x + size2, y, size2);
		go(x, y + size2, size2);
		go(x + size2, y + size2, size2);
	}
	else {
		if (a[x][y] == 0)c0++;
		else c1++;
	}
}
vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	n = arr.size();
	a = arr;
	c0 = 0; c1 = 0;
	go(0,0,n);
	answer.push_back(c0);
	answer.push_back(c1);
	return answer;
}
