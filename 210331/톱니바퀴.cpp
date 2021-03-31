#include <bits/stdc++.h>

using namespace std;

int k, d[4], a[4][8];

void rotate() {
	for (int j = 0; j < 4; j++) {
		int copy[8];
    
		if (d[j] == 1) {
			for (int i = 1; i <= 7; i++) {
				copy[i] = a[j][i - 1];
			}
			copy[0] = a[j][7];
		}
    
		else if (d[j] == -1) {
			for (int i = 0; i <= 6; i++) {
				copy[i] = a[j][i + 1];
			}
			copy[7] = a[j][0];
		}
    
		else {
		}
    
		if (d[j] != 0) {
			for (int i = 0; i < 8; i++) {
				a[j][i] = copy[i];
			}
		}    
	}
}

int main() {
	for (int i=0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	
	
	cin >> k;
	while (k--) {
		int n, dir;
		cin >> n >> dir;
		n--;
		memset(d, 0, sizeof(d));
    
		d[n] = dir;
		for (int i = n; i <= 2; i++) {
			if (a[i][2] != a[i + 1][6]) {
				d[i + 1] = -d[i];
			}
		}
    
		for (int i = n; i >= 1; i--) {
			if (a[i][6] != a[i - 1][2]) {
				d[i - 1] = -d[i];
			}
		}    
		rotate();
	}
  
	int rs=0;
	for (int i = 0; i < 4; i++) {
		if (a[i][0]==1) rs += pow(2, i);
	}
	cout << rs;
}
