//45분
#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;

int T,N,M;
int m[8][8]{};
int virm[8][8]{};
int samm[8][8]{};
bool vi[8][8]{};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
pii samPos;
vector<pii> stk;

void bfsVirus(){
    memset(vi,0,sizeof(vi));
    memset(virm,-1,sizeof(virm));
    queue<pair<int,pii>> q;
    for(auto val : stk){
        q.push({0,val});
        vi[val.xx][val.yy] = true;
        virm[val.xx][val.yy] = 0;
    }

    while(!q.empty()){
        int cd = q.front().xx;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        for(int i=0; i<4; i++){
            int nd = cd + 1;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx]) continue;
            if(m[ny][nx]==1) continue;
            q.push({nd,{ny,nx}});
            vi[ny][nx] = true;
            virm[ny][nx] = nd;
        }
    }
}

void bfsSam(){
    memset(vi,0,sizeof(vi));
    memset(samm,-1,sizeof(samm));
    queue<pair<int,pii>> q;
    q.push({0,samPos});
    vi[samPos.xx][samPos.yy] = true;
    samm[samPos.xx][samPos.yy] = 0;

    while(!q.empty()){
        int cd = q.front().xx;
        int cy = q.front().yy.xx;
        int cx = q.front().yy.yy;
        q.pop();

        for(int i=0; i<4; i++){
            int nd = cd + 1;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx]) continue;
            if(m[ny][nx]==1) continue;
            q.push({nd,{ny,nx}});
            vi[ny][nx] = true;
            samm[ny][nx] = nd;
        }
    }
}

bool chkZom(){ // CANNOT ESCAPE
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(virm[i][j]==-1 && samm[i][j]!=-1) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=1; t<=T; t++){
        stk.clear();
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>m[i][j];
                if(m[i][j]==3) samPos = {i,j};
                if(m[i][j]==2) stk.push_back({i,j});
            }
        }

        bfsVirus();
        bfsSam();

        int ans = INF;
        bool chk = false;
        for(int i=0; i<N; i++){
            if(samm[i][0]==-1) continue;
            else chk = true;
            if(virm[i][0]==-1 || virm[i][0] > samm[i][0]) ans = min(ans, samm[i][0]+1);
        }
        for(int i=0; i<N; i++){
            if(samm[i][M-1]==-1) continue;
            else chk = true;
            if(virm[i][M-1]==-1 || virm[i][M-1] > samm[i][M-1]) ans = min(ans, samm[i][M-1]+1);
        }
        for(int j=1; j<M-1; j++){
            if(samm[0][j]==-1) continue;
            else chk = true;
            if(virm[0][j]==-1 || virm[0][j] > samm[0][j]) ans = min(ans, samm[0][j]+1);
        }
        for(int j=1; j<M-1; j++){
            if(samm[N-1][j]==-1) continue;
            else chk = true;
            if(virm[N-1][j]==-1 || virm[N-1][j] > samm[N-1][j]) ans = min(ans, samm[N-1][j]+1);
        }
        
        if(!chk) {
            if(chkZom()) cout<<'#'<<t<<' '<<"CANNOT ESCAPE"<<'\n';
            else cout<<'#'<<t<<' '<<"ZOMBIE"<<'\n';
        }
        else {
            if(ans==INF) cout<<'#'<<t<<' '<<"ZOMBIE"<<'\n';
            else cout<<'#'<<t<<' '<<ans<<'\n';
        }
    }
}