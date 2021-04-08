#include <iostream>

using namespace std;

int n, b, c, p[1000000];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	cin >> b >> c;
  
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		p[i] -= b;
		ret++;
		if (p[i] > 0) {
			ret += p[i] / c;
			if (p[i] % c != 0) {
				ret++;
			}
		}				
	}
	cout << ret;
}
