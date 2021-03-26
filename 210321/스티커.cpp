#include <bits/stdc++.h>
 
using namespace std;
 
int s[2][100001], value[2][100001], t;
 
int main() {
    cin >> t;
 
    for (int k = 0; k < t; k++) {        
        int n;
        cin >> n;
 
        for (int i = 0; i < 2; i++){
            for (int j = 1; j <= n; j++) {
                cin >> s[i][j];
            }
        }
 
        value[0][0] = 0;
		    value[1][0] = 0;
		
        value[0][1] = s[0][1];
        value[1][1] = s[1][1];
 
        for (int i = 2; i <= n; i++) {
            value[0][i] = max(value[1][i - 1], value[1][i - 2]) + s[0][i];
            value[1][i] = max(value[0][i - 1], value[0][i - 2]) + s[1][i];
        }
        cout << max(value[0][n], value[1][n]) << endl;
    } 
}
