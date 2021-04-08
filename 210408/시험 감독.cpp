#include <iostream>
using namespace std;
int N, B, C;
int arr[1000001];
int main()
{
	cin >> N;
	int total = 0;
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		answer++;
		arr[i] -= B;
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] <= 0) {

		}
		else {
			answer += arr[i] / C;
			if (arr[i] % C != 0)
				answer++;
		}
	}
	printf("%lld\n", answer);
	return 0;
}