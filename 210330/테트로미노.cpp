#include <iostream>

using namespace std;
int n, m, ans = -1;
int board[503][503];

char map[19][4][5] = {
{
	{"1111"},
	{"0000"},
	{"0000"},
	{"0000"},
},
{
	{"1000"},
	{"1000"},
	{"1000"},
	{"1000"},
},
{
	{"1100"},
	{"1100"},
	{"0000"},
	{"0000"},
},
{
	{"1000"},
	{"1000"},
	{"1100"},
	{"0000"},
},
{
	{"1100"},
	{"0100"},
	{"0100"},
	{"0000"},
},
{
	{"0010"},
	{"1110"},
	{"0000"},
	{"0000"},
},
{
	{"1110"},
	{"1000"},
	{"0000"},
	{"0000"},
},
{
	{"1110"},
	{"0010"},
	{"0000"},
	{"0000"},
},
{
	{"1000"},
	{"1110"},
	{"0000"},
	{"0000"},
},
{
	{"1100"},
	{"1000"},
	{"1000"},
	{"0000"},
},
{
	{"0100"},
	{"0100"},
	{"1100"},
	{"0000"},
},
{
	{"1000"},
	{"1100"},
	{"0100"},
	{"0000"},
},
{
	{"0110"},
	{"1100"},
	{"0000"},
	{"0000"},
},
{
	{"0100"},
	{"1100"},
	{"1000"},
	{"0000"},
},
{
	{"1100"},
	{"0110"},
	{"0000"},
	{"0000"},
},
{
	{"1110"},
	{"0100"},
	{"0000"},
	{"0000"},
},
{
	{"0100"},
	{"1100"},
	{"0100"},
	{"0000"},
},
{
	{"0100"},
	{"1110"},
	{"0000"},
	{"0000"},
},
{
	{"1000"},
	{"1100"},
	{"1000"},
	{"0000"},
},
};

int go(int a, int b, int c) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[c][i][j] == '1') sum += board[a + i][b + j];
		}
	}
	return sum;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m; j < m + 3; j++) {
			board[i][j] = -10000;
		}
	}
	for (int i = n; i < n + 3; i++) {
		for (int j = 0; j < m + 3; j++) {
			board[i][j] = -10000;
		}
	}

	for (int c = 0; c < 19; c++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				int res = go(a, b, c);
				if (res > ans)ans = res;
			}
		}
	}
	cout << ans;
}
