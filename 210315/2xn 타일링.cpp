#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i-1] + arr[i - 2]) % 10007 ;
	}

	cout << arr[n];

}