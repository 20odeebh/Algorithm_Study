#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int T,K;
int cir[4][8]{};
int p[4]{};
int LR[4][2]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>K;
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                cin>>cir[i][j];
            }
        }

        int a,b;
        memset(p,0,sizeof(p));
        for(int k=0; k<K; k++){
            cin>>a>>b; 
            a--; b*=-1;
            for(int i=0; i<4; i++){
                LR[i][0] = cir[i][(p[i]+6)%8];
                LR[i][1] = cir[i][(p[i]+2)%8];
            }

            p[a] = (p[a]+8+b)%8;
            int preb = b;
            for(int i=a-1; i>=0; i--){
                if(LR[i+1][0]^LR[i][1]) {
                    p[i] = (p[i]+8+(preb*-1))%8;
                    preb *= -1;
                } else break;
            }
            preb = b;
            for(int i=a+1; i<4; i++){
                if(LR[i-1][1]^LR[i][0]) {
                    p[i] = (p[i]+8+(preb*-1))%8;
                    preb *= -1;
                } else break;
            }
        }
        int ans = 0, mul = 1;
        for(int i=0; i<4; i++){
            ans += (cir[i][p[i]])*mul;
            mul*=2;
        }
        
        cout<<'#'<<t<<' '<<ans<<'\n';
    }

}