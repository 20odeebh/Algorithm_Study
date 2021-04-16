#include<bits/stdc++.h>
#define xx first
#define yy second
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> pii;

int T,N,idx=0, minTime=INF;
int m[11][11]{};
pii ed1={INF,INF}, ed2={INF,INF};
int str1, str2;
pii men[11]{};

vector<int> v1;
vector<int> v2;

int solve(){
    vector<int> t1 = v1;
    vector<int> t2 = v2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    
    int l1=0,r1=0, l2=0,r2=0, time=0;
    // 미완
    // 1번 계단 총 시간
    // 2번 계단 총 시간
    
    return time;
}

void dfs(int dpt){
    if(dpt==idx) {
        minTime = min(minTime, solve());
        return;
    }

    v1.push_back(men[dpt].xx);
    dfs(dpt+1);
    v1.pop_back();
    
    v2.push_back(men[dpt].yy);
    dfs(dpt+1);
    v2.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int t=1; t<=T; t++){
        minTime = INF;
        ed1={INF,INF}, ed2={INF,INF};
        cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>m[i][j];
                if(m[i][j]>1) {
                    if(ed1.xx==INF) {
                        ed1 = pii(i,j);
                        str1 = m[i][j];
                    }
                    else {
                        ed2 = pii(i,j);
                        str2 = m[i][j];
                    }
                }
            }
        }
        idx = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(m[i][j]==1) {
                    int a = abs(ed1.xx-i) + abs(ed1.yy-j);
                    int b = abs(ed2.xx-i) + abs(ed2.yy-j);
                    men[idx++] = pii(a+1,b+1);
                }
            }
        }

        dfs(0);
        cout<<'#'<<t<<' '<<minTime<<'\n';
    }
    
}