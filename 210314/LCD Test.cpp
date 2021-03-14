#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>
#include <memory.h>
#include <unordered_map>

using namespace std;
int s;
string n;
char arr[250][250];
int x, y;

void verti(int y, int x1, int x2) {
	for (int i = x1; i < x2; i++) {
		arr[i][y] = '|';
	}
}

void hori(int x, int y1, int y2) {
	for (int i = y1; i < y2-2; i++)
		arr[x][i] = '-';
}

void draw(int i, int num) {
	// 각각 경우의 따라 가로 세로 그리기
	if(num!=5 && num!=6)
		verti(i*y+y-1+i, 1,x/2);
	if(num!=2)
		verti(i*y + y-1+i, x / 2 + 1, x-1);
	if (num == 4 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0)
		verti(i*y+i, 1, x / 2);
	if (num == 2 || num == 6 || num == 8 || num == 8 || num == 0)
		verti(i*y+i, x / 2 + 1, x - 1);
	if (num != 1 && num != 4) 
		hori(0, i*y + 1+i, i*y + 1 + y+i);
	if (num != 1 && num != 7 && num != 0) 
		hori(x/2, i*y + 1 + i, i*y + 1 + y + i);
	if (num != 1 && num != 4 && num != 7) 
		hori(x - 1, i*y + 1 + i, i*y + 1 + y + i);
}

int main() {
	cin >> s >> n;
	// 세로 가로 길이
	x = 2 * s + 3;
	y = s + 2;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y*n.size() + n.size(); j++)
			arr[i][j] = ' ';
	}

	// i번째 위치에 num을 그리는 함수 호출
	for (int i = 0; i < n.size(); i++) {
		int num = n[i] - '0';
		draw(i, num);
	}
	// 범위 주의
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y*n.size()+n.size()-1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

