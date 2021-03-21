#include <iostream>
using namespace std;
int main() {
	int n;
	long long d[100];
	d[1] = 1;
	d[2] = 1;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];

}