#include <iostream>

using namespace std;

int n,ans,d[1001][10];

int main() {
	cin>>n;

	for(int i = 0; i < 10; ++i)
		d[1][i] = 1;

	for(int i = 2; i <= n; ++i) 
	{
		for(int j = 0; j < 10; ++j) 
		{
			for(int k = j; k < 10; ++k)
				d[i][j] = (d[i][j] + d[i-1][k]) % 10007;
		}
	}
	
	for(int i = 0; i < 10; ++i)
		ans = (ans + d[n][i]) % 10007;

	cout<<ans<<endl;
}
