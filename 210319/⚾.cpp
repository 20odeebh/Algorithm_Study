#include<bits/stdc++.h>

using namespace std;

int n, res[52][10], num[10], o[10], p[10], MAX = -1;
bool isused[10];

void play() {
	int hitter = 1, score = 0;
	for (int i = 1; i <= n; i++) { 
	  int outCnt = 0;

		while (1) {
			if (res[i][o[hitter]] == 0) { 
				hitter++;
				if (hitter >= 10) hitter = 1;
				outCnt++;
				if (outCnt == 3) {
				
					for (int j = 1; j <= 9; j++) p[j] = 0;
					break;
				}
			}
			else {
				
				for (int j = 1; j <= 9; j++) {
					if (p[j] > 0 || j == o[hitter]) { 
						p[j] += res[i][o[hitter]];
						if (p[j] >= 4) {
							p[j] = 0;
							score++;
						}
					}
				}
				hitter++;
				if (hitter >= 10) hitter = 1;
			}
		}
	}
	if (MAX < score) MAX = score;
}

void func(int k) {
	if (k > 9) { 
		play();
		return;
	}
	for (int i = 2; i <= 9; i++) {
		if (!isused[i]) {
			o[k] = i;
			isused[i] = true;
			if (k == 3) func(k + 2); 
			else func(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	for (int i = 1; i <= 9; i++){
		num[i] = i;
  }
	isused[1] = true; 
	o[4] = 1; 
	cin >> n;
	
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= 9; j++) 
			cin >> res[i][j];
	
	func(1);
	cout << MAX << '\n';
}
