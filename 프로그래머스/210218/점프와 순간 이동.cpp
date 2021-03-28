#include <bits/stdc++.h>
using namespace std;
//연산을 거꾸로
//2로 나누면서 1씩 빼는 과정
int solution(int n)
{
	int ans = 0;
	while (n) {
		if (n % 2) {
			n--;
			ans++;
		}
		n /= 2;
	}

	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
}