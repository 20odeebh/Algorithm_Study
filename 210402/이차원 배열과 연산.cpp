#include <bits/stdc++.h>

using namespace std;

int r, c, k, t, row = 3, col = 3;
int arr[500][500];

bool comp(pair<int,int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void exec_r() {
	int temp[500][500] = { 0, };
	int mxC = 0;
  
	for (int i = 0; i < row; i++)  {
		map<int, int> m;
		vector<pair<int, int>> v;
		int size = 0;
		
		for (int j = 0; j < col; j++) {
			if (arr[i][j] != 0) {
				m[arr[i][j]]++;
			}
		}
		
		for (auto a : m) {
			v.push_back({ a.first,a.second });
		}
		
		sort(v.begin(), v.end(), comp);
		
		size = (m.size()*2 > 50) ? 50 : m.size()*2;
		mxC = max(mxC, size);

		for (int j = 0; j < v.size(); j++) {
			if (j == 50) break;
			temp[i][(j * 2)] = v[j].first;
			temp[i][(j * 2) + 1] = v[j].second;
		}		
	}
	memset(arr, 0, sizeof(arr));
	memcpy(arr, temp, sizeof(arr));
	col = mxC;
}

void exec_c() {
	int temp[500][500] = { 0, };
	int mxR = 0;
  
	for (int i = 0; i < col; i++) {
		map<int, int> m;
		vector<pair<int, int>> v;
		int size = 0;

		for (int j = 0; j < row; j++) {
			if (arr[j][i] != 0) {
				m[arr[j][i]]++;
			}
		}

		for (auto a : m) {
			v.push_back({ a.first,a.second });
		}

		sort(v.begin(), v.end(), comp);

		size = (m.size()*2 > 50) ? 50 : m.size()*2;
		mxR = max(mxR, size);

		for (int j = 0; j < v.size(); j++) {
			if (j == 50) break;
			temp[(j * 2)][i] = v[j].first;
			temp[(j * 2)+1][i] = v[j].second;
		}
	}
	memset(arr, 0, sizeof(arr));
	memcpy(arr, temp, sizeof(arr));
	row = mxR;
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin>>arr[i][j];
		}
	}
  
	while (true) {
		if (arr[r - 1][c - 1] == k) break;
		if (t == 100) {
			t = -1;
			break;
		}
    
		t++;
		if (row >= col) exec_r();
		else exec_c();
		
	}
	cout << t;	
}
