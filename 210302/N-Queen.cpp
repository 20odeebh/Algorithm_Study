#include <bits/stdc++.h>

using namespace std;

int answer = 0;
bool check[12][12];

set <pair<int,int>> impossible_check(int y, int x, int n) {
	set <pair<int,int>> s;
	
	for (int i = 0; i < n; i++) {
		if(!check[y][i])
			s.insert({ y,i });
	}

	for (int i = 0; i < n; i++) {
		if (!check[i][x])
			s.insert({ i,x });
	}
	for (int i = 0; i < n; i++) {
		
		if (y - i >= 0 && x - i >= 0 && y - i < n && x - i < n) {
			if (!check[y-i][x-i])
				s.insert({ y - i,x - i });
		}
		
		if (y - i >= 0 && x + i >= 0 && y - i < n && x + i < n) {
			if (!check[y-i][x+i])
				s.insert({ y - i,x + i });
		}
		
		if (y + i >= 0 && x - i >= 0 && y + i < n && x - i < n) {
			if (!check[i][x-i])
				s.insert({ y + i,x - i });
		}
		
		if (y + i >= 0 && x + i >= 0 && y + i < n && x + i < n) {
			if (!check[y+i][x+i])
				s.insert({ y + i,x + i });
		}
	}

	return s;
}

void dfs(int y, int x, int n, int cnt) {
	if(check[y][x] == false && x<n) {
		
		if (cnt == n - 1) {
			answer += 1;
			return;
		}

		set <pair<int, int>> s = impossible_check(y, x, n);
		for (auto i : s) {
			int yy = i.first;
			int xx = i.second;
			check[yy][xx] = true;
		}
		
		for (int k = 0; k < n; k++) {
			dfs(k, x + 1, n, cnt + 1);
		}

		for (auto i : s) {
			int yy = i.first;
			int xx = i.second;
			check[yy][xx] = false;
		}
	}

}

int solution(int n) {

	for (int i = 0; i < n; i++) {
		dfs(i, 0, n, 0);
	}

	return answer;
}