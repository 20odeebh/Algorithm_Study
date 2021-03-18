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
// 그리디한 경우로서는 모두 해결할 수 없다.
int arr[10][10];
int answer = INT_MAX;
int remain[6] = { 0,5,5,5,5,5 };

bool canGo(int x, int y, int k) {
	if (x + k > 10 || y + k > 10)
		return false;

	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (arr[i][j] != 1)
				return false;
		}
	}
	return true;
}

void Go(int x, int y, int k, int num) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			arr[i][j] = num;
		}
	}
	return;
}

bool removeAll() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1)
				return false;
		}
	}
	return true;
}


void dfs(int cnt) {
	if (removeAll()) {
		answer = min(cnt, answer);
		return;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1) {
				// 1인 경우에는 5부터 색종이를 덮어나간다.
				for (int k = 5; k > 0; k--) {
					if (canGo(i, j, k) && remain[k]>0) {
						remain[k]--;
						Go(i, j, k, 0);
						dfs(cnt+1);
						remain[k]++;
						Go(i, j, k, 1);
					}
				}
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0);
	if (answer == INT_MAX)
		cout << -1;
	else
		cout << answer;
}

