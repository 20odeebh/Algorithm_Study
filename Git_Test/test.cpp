#include <bits/stdc++.h>
using namespace std;
struct A {
	long long MIN, MAX, NOW;
};
long long a[200001];
A tree[500001];
string s;
void init(int node, int start, int end) {
	if (start == end) {
		if (s[start] == '+') {
			tree[node].MIN = 0;
			tree[node].MAX = 1;
			tree[node].NOW = 1;
		}
		else {
			tree[node].MIN = -1;
			tree[node].MAX = 0;
			tree[node].NOW = -1;
		}
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node].MIN = min(tree[node * 2].MIN, tree[node * 2].NOW + tree[node * 2 + 1].MIN);
	tree[node].MAX = max(tree[node * 2].MAX, tree[node * 2].NOW + tree[node * 2 + 1].MAX);
	tree[node].NOW = tree[node * 2].NOW + tree[node * 2 + 1].NOW;
}
A query(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return{ 0, 0, 0 };
	if (start >= i && end <= j)return tree[node];
	int mid = (start + end) / 2;
	A left = query(node * 2, start, mid, i, j);
	A right = query(node * 2 + 1, mid + 1, end, i, j);
	A middle = left;
	middle.MIN = min(left.MIN, left.NOW + right.MIN);
	middle.MAX = max(left.MAX, left.NOW + right.MAX);
	middle.NOW = left.NOW + right.NOW;
	return middle;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;	
		cin >> s;
		s = " " + s;
		init(1, 1, n);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			A left,right,middle;
			if (x == 1) {
				left = { 0,0,0 };
			}
			else {
				left = query(1, 1, n, 1, x - 1);
			}
			//cout << left.MIN << ' ' << left.MAX << ' ' << left.NOW << '\n';
			if (y == n) {
				right = { 0,0,0 };
			}
			else {
				right = query(1, 1, n, y + 1, n);
			}
			//cout << right.MIN << ' ' << right.MAX << ' ' << right.NOW << '\n';
			middle.MIN = min(left.MIN, left.NOW + right.MIN);
			middle.MAX = max(left.MAX, left.NOW + right.MAX);
			cout << middle.MAX - middle.MIN + 1 << '\n';
		}
	}
}