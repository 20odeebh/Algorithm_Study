#include<iostream>

using namespace std;

int packs[1001], dp[10001], N;

int max(int x, int y) {
	if (x > y) return x;
	return y;
}

int main() {
    cin>>N;
    
	for (int i = 1; i <= N; i++)    cin>>packs[i];

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			dp[i] = max(dp[i], dp[i - j] + packs[j]);
        }
    }

	cout<<dp[N];
}
