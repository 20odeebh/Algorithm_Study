#include <bits/stdc++.h>
using namespace std;
//d[i]= i를 1,2,3을 더해서 만드는 경우의 수
int d[12];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	d[0] = 1;
	for (int i = 1; i <= 10; i++) {
		d[i] += d[i - 1];
		if (i >= 2)d[i] += d[i - 2];
		if (i >= 3)d[i] += d[i - 3];
	}
	while (T--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}