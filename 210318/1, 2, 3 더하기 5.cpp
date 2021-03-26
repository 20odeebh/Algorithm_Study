#include<bits/stdc++.h>

using namespace std;

int T, n;
long long ans, d[100001][4];

int main(){
	cin >> T;

	while (T--){
		cin >> n;

		d[1][1] = 1, d[1][2] = 0, d[1][3] = 0;

		d[2][1] = 0, d[2][2] = 1, d[2][3] = 0;

		d[3][1] = 1, d[3][2] = 1, d[3][3] = 1;

		for (int i = 4; i <= n; i++){
			d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
			d[i][2] = (d[i - 2][1] + d[i - 2][3]) % 1000000009;
			d[i][3] = (d[i - 3][1] + d[i - 3][2]) % 1000000009;
		}

		ans = (d[n][1] + d[n][2] + d[n][3]) % 1000000009;
		cout << ans << '\n';
	}	
}
