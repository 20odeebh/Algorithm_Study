#include<bits/stdc++.h>
using namespace std;

int T,N,X; // T:[1,50], N:[6,20], X:[2,4]
int m[21][21]{}; // [1,6]
int m2[21][21]{};
int cnt[21][21]{};

int findRoad(int m[][21]){
    int sum = 0;
    for(int i=0; i<N; i++){
        bool chk = true;
        for(int j=1; j<N; j++){
            if(abs(m[i][j-1]-m[i][j])>1) {chk = false; break;}
            if(m[i][j-1]-1==m[i][j]){
                for(int k=j; k<j+X; k++){
                    if(k==N || m[i][k]!=m[i][j]) {chk = false; break;}
                    cnt[i][k]++;
                }
                if(!chk) break;
                j = j+X-1;
            }
        }
        if(!chk) continue;
        for(int j=N-2; j>=0; j--){
            if(m[i][j+1]-1==m[i][j]){
                for(int k=j; k>j-X; k--){
                    if(k==-1 || m[i][k]!=m[i][j]) {chk = false; break;}
                    cnt[i][k]++;
                    if(cnt[i][k]>1) {chk = false; break;}
                }
                if(!chk) break;
                j = j-X+1;
            }
        }
        if(chk) sum++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N>>X;
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>m[i][j];
                m2[j][i] = m[i][j];
            }
        }
        
        int sum = findRoad(m);
        memset(cnt,0,sizeof(cnt));
        sum += findRoad(m2);
        cout<<'#'<<t<<' '<<sum<<'\n';
    }
}