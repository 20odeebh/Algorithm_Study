// 시험 감독

#include <stdio.h>
#define ll long long
int arr[1000001];

int main() {
	int n;
	ll master = 0, slave = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	int b, c;
	scanf(" %d %d", &b, &c);
	for (int i = 0; i < n; i++) {
		arr[i] -= b;
		master++;
		if (arr[i] <= 0) continue;
		if (arr[i] % c > 0) slave += arr[i] / c + 1;
		else slave += arr[i] / c;
	}
	printf("%lld\n", master + slave);
	return 0;
}