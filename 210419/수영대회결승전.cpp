// 25분
// 다익스트라
#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int INF = 0x3f3f3f3f;

int T,N;
int m[15][15]{};
int d[15][15]{};
pii st, ed;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void dijk(){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pq.push({0,st});
    d[st.xx][st.yy] = 0;

    while(!pq.empty()) {
        int cd = pq.top().xx;
        int cy = pq.top().yy.xx;
        int cx = pq.top().yy.yy;
        pq.pop();

        if(d[cy][cx] < cd) continue;

        for(int i=0; i<4; i++){
            int nd = cd;
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny<0 || nx<0 || ny>=N || nx>=N || m[ny][nx]==1) continue;
            if(!m[ny][nx]) nd++;
            else nd += (3-(cd%3));

            if(d[ny][nx] > nd){
                pq.push({nd,{ny,nx}});
                d[ny][nx] = nd;
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=1; t<=T; t++){
        memset(d,0x3f,sizeof(d));
        cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>m[i][j];
            }
        }
        cin>>st.xx>>st.yy;
        cin>>ed.xx>>ed.yy;

        dijk();
        int ans = d[ed.xx][ed.yy];
        if(ans==INF) cout<<'#'<<t<<' '<<-1<<'\n';
        else cout<<'#'<<t<<' '<<ans<<'\n';
    }
}