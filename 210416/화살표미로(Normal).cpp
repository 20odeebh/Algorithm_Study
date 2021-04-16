// WA

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct Info {
    int y,x,l,r; // y,x,dir,cnt
    Info(int y=0, int x=0, int l=0, int r=0)
    : y(y), x(x), l(l), r(r) {}
};

struct comp{
    bool operator()(Info &a, Info &b){
        return a.l+a.r > b.l+b.r;
    }
};

int N,M,K; // 50, 50 ,150
int m[51][51]{};
bool vi[51][51][151][151]{};
int dist[51][51]{};
int dy[4] = {-1,0,1,0}; // U,R,D,L
int dx[4] = {0,1,0,-1};

bool solve(){
    priority_queue<Info,vector<Info>, comp> pq;
    pq.push(Info(0,0,0,0));
    vi[0][0][0][0] = true;
    dist[0][0] = 0;

    while(!pq.empty()){
        int cy = pq.top().y;
        int cx = pq.top().x;
        int cl = pq.top().l;
        int cr = pq.top().r;
        pq.pop();

        if(dist[cy][cx] < cl+cr) continue;
        if(cy==N-1 && cx==M-1)
            if(max(cl,cr)<=K) 
                return true;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=M) continue;
            int cd = m[cy][cx]+4;
            int nl=cl,nr=cr;
            bool chk = false;
            if(cd%4 == i) nl = cl, nr = cr;
            else if((cd-1)%4 == i) nl = cl+1, nr = cr;
            else if((cd+1)%4 == i) nl = cl, nr = cr+1;
            else if((cd+2)%4 == i) {
                nl = cl + 2;
                nr = cr;
                chk = true;
            }
            
            if(dist[ny][nx] >= (nl+nr)){
                if(max(nl,nr) > K) continue;
                if(vi[ny][nx][nl][nr]) continue;
                else vi[ny][nx][nl][nr] = true;
                dist[ny][nx] = nl+nr;
                pq.push(Info(ny,nx,nl,nr));
                if(!chk) continue;
                nl -=2; nr +=2;
                if(vi[ny][nx][nl][nr]) continue;
                else vi[ny][nx][nl][nr] = true;
                pq.push(Info(ny,nx,nl,nr));
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    string str;
    for(int i=0; i<N; i++){
        cin>>str;
        for(int j=0; j<M; j++){
            if(str[j]=='U') m[i][j] = 0;
            else if(str[j]=='R') m[i][j] = 1;
            else if(str[j]=='D') m[i][j] = 2;
            else if(str[j]=='L') m[i][j] = 3;
        }
    }
    memset(dist,0x3f,sizeof(dist));
    if(solve()) cout<<"Yes";
    else cout<<"No";
}