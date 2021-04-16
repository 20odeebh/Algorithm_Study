#include<bits/stdc++.h>
using namespace std;

struct Info{
    int y, x, cnt, dir;
    Info(int y=0, int x=0, int cnt=0, int dir=0)
    : y(y), x(x), cnt(cnt), dir(dir) {}    
};

int T,N,M,K;
int m[101][101]{};
int msum[101][101]{};
vector<Info> v;
bool vi[1001]{};
int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};

void move() {
    for(int i=0; i<v.size(); i++){
        if(vi[i]) continue;
        int cdir = v[i].dir;
        int ny = v[i].y + dy[cdir];
        int nx = v[i].x + dx[cdir];
        if(ny==0 || nx==0 || ny==N-1 || nx==N-1){
            if(cdir==1) v[i].dir = 2;
            else if(cdir==2) v[i].dir = 1;
            else if(cdir==3) v[i].dir = 4;
            else if(cdir==4) v[i].dir = 3;
            v[i].cnt = v[i].cnt / 2;
            if(v[i].cnt==0) vi[i] = true;
        }
        v[i].y = ny;
        v[i].x = nx;
    }

    
}

void merge(){
    memset(m,-1,sizeof(m));
    memset(msum,0,sizeof(msum));
    for(int i=0; i<v.size(); i++){
        if(vi[i]) continue;
        int y = v[i].y;
        int x = v[i].x;
        if(m[y][x] == -1) {
            m[y][x] = i;
            msum[y][x] = v[i].cnt;
        }
        else {
            msum[y][x] += v[i].cnt;
            if(v[i].cnt > v[m[y][x]].cnt){
                vi[m[y][x]] = true;
                m[y][x] = i;
            } else {
                vi[i] = true;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(m[i][j]>-1) {
                v[m[i][j]].cnt = msum[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=1; t<=T; t++){
        v.clear();
        memset(vi,0,sizeof(vi));
        cin>>N>>M>>K;
        int a,b,c,d;
        for(int i=0; i<K; i++){
            cin>>a>>b>>c>>d;
            v.push_back(Info(a,b,c,d));
        }
        
        while(M--){
            move();
            merge();
        }

        int ans = 0;
        for(int i=0; i<v.size(); i++){
            if(vi[i]) continue;
            ans += v[i].cnt;
        }
        cout<<'#'<<t<<' '<<ans<<'\n';
    }
    
}
/*
1
7 2 9
1 1 7 1
2 1 7 1
5 1 5 4
3 2 8 4
4 3 14 1
3 4 3 3
1 5 8 2
3 5 100 1
5 5 1 1

*/