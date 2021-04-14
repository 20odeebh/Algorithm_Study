#include <cstdio>
#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int X[1000], Y[1000], D[1000], K[1000], MAP[4001][4001], dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
 
int main(int argc, char** argv)
{
    int T;  
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
         
        for (int n = 0; n < N; n++)
        {
            int x, y;
            cin >> x >> y;
            X[n] = 2 * x; Y[n] = 2 * y;
            cin >> D[n] >> K[n];
            MAP[2*x + 2000][2*y + 2000] = K[n];
        }
 
        int ans = 0;
         
        while(true){
            int cnt = 0;
            for (int n = 0; n < N; n++){
                if (K[n] == 0) continue;
                cnt++;
                MAP[X[n] + 2000][Y[n] + 2000] -= K[n];
                X[n] += dx[D[n]];
                Y[n] += dy[D[n]];
 
                if (X[n] < -2000 || X[n] > 2000 || Y[n] < -2000 || Y[n] > 2000){
                    K[n] = 0;
                    continue;
                }
                MAP[X[n] + 2000][Y[n] + 2000] += K[n];
            }
            if (cnt == 0) break;
 
            for (int n = 0; n < N; n++){
                if (K[n] == 0) continue;
 
                if (K[n] != MAP[X[n] + 2000][Y[n] + 2000]){
                    ans += K[n];
                    K[n] = 0;
                    MAP[X[n] + 2000][Y[n] + 2000] = 0;
                }
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
