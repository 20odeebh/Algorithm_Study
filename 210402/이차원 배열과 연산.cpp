#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int R, C, K;
int rowSize = 3, colSize = 3;
int field[101][101];
unordered_map<int, int> m;
bool cmp(int n1, int n2)
{
	if (m[n1] == m[n2]) {
		return n1 < n2;
	}
	return m[n1] < m[n2];
}
bool IsOver()
{
	if (field[R][C] == K)
		return true;
	else
		return false;
}
void _R()
{
	vector<vector<int>> arr(rowSize + 1, vector<int>());
	vector<int> result;
	int max_size = 0;
	for (int r = 1; r <= rowSize; r++) {
		auto& v = arr[r];
		for (int c = 1; c <= colSize; c++) {
			auto num = field[r][c];
			if (num != 0) {
				m[num]++;
				if (find(v.begin(), v.end(), num) == v.end())
					v.push_back(num);
			}
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			result.push_back(v[i]);
			result.push_back(m[v[i]]);
		}
		for (int i = 1; i <= 100; i++) {
			if (i - 1 < result.size())
				field[r][i] = result[i - 1];
			else
				field[r][i] = 0;
		}
		if (result.size() >= 100)
			max_size = 100;
		else
			max_size = max((int)result.size(), max_size);
		m.clear();
		result.clear();
	}
	colSize = max_size;
}
void _C()
{
	vector<vector<int>> arr(colSize + 1, vector<int>());
	vector<int> result;
	int max_size = 0;
	for (int c = 1; c <= colSize; c++) {
		auto& v = arr[c];
		for (int r = 1; r <= rowSize; r++) {
			auto num = field[r][c];
			if (num != 0) {
				m[num]++;
				if (find(v.begin(), v.end(), num) == v.end())
					v.push_back(num);
			}
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < v.size(); i++) {
			result.push_back(v[i]);
			result.push_back(m[v[i]]);
		}
		for (int i = 1; i <= 100; i++) {
			if (i - 1 < result.size())
				field[i][c] = result[i - 1];
			else
				field[i][c] = 0;
		}
		if (result.size() >= 100)
			max_size = 100;
		else
			max_size = max((int)result.size(), max_size);
		m.clear();
		result.clear();
	}
	rowSize = max_size;
}
int main()
{
	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> field[i][j];
	int time = 0;
	while (!IsOver()) {
		if (time >= 100) {
			printf("-1\n");
			return 0;
		}
		time++;
		if (rowSize >= colSize) {
			_R();
		}
		else {
			_C();
		}
	}
	printf("%d\n", time);
	return 0;
}