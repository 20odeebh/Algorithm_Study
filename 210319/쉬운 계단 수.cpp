#include <bits/stdc++.h>
 
using namespace std;
 
long long d[101][10], s = 1000000000LL, ans;
int n;

int main() {   
    cin>>n;
    d[1][0] = 0;
    
    for (int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }
    
    for (int i = 2; i <= 100; i++) {
        d[i][0] = d[i-1][1] % s;
        d[i][9] = d[i-1][8] % s;
        for (int j = 1; j <= 8; j++) {
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % s;
        }
    }
    
    for (int i = 0; i <= 9; i++) {
        ans = (ans%s) + (d[n][i]%s);
    }
    
    printf("%lld", ans%s);
}
