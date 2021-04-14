#include<iostream>
#include<algorithm>
#include<vector>
#define xx first
#define yy second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> dpii;

int T,M,A;
vector<int> m[11][11]{};
vector<dpii> bc;
int ua[101]{};
int ub[101]{};
int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int k=1; k<=T; k++){
        cin>>M>>A;
        int sum = 0;
        bc.clear();
        for(int i=1; i<=10; i++){
            for(int j=1; j<=10; j++){
                m[i][j].clear();
            }
        }
        for(int i=1; i<=M; i++) cin>>ua[i];
        for(int i=1; i<=M; i++) cin>>ub[i];
        int a,b,c,d;
        for(int i=0; i<A; i++) {
            cin>>a>>b>>c>>d;
            bc.push_back({{b,a},{c,d}});
        }
        sort(bc.begin(), bc.end(), [&](dpii x, dpii y)->bool{
            return x.yy.yy > y.yy.yy;
        });
        
        for(int i=1; i<=10; i++){
            for(int j=1; j<=10; j++){
                for(int z=0; z<A; z++) {
                    int tmp = abs(i-bc[z].xx.xx) + abs(j-bc[z].xx.yy);
                    if(tmp <= bc[z].yy.xx){
                        m[i][j].push_back(z);
                    }
                }
            }
        }
        int cay = 1, cax = 1;
        int cby = 10, cbx = 10;
        for(int i=0; i<=M; i++){
            int nay = cay + dy[ua[i]];
            int nax = cax + dx[ua[i]];
            int nby = cby + dy[ub[i]];
            int nbx = cbx + dx[ub[i]];
            auto x = m[nay][nax];
            auto y = m[nby][nbx];
            if(x.size()==0 && y.size()==0);
            else if(x.size()>0 && y.size()==0) sum += bc[x[0]].yy.yy;
            else if(x.size()==0 && y.size()>0) sum += bc[y[0]].yy.yy;
            else if(x.size()==1 && y.size()==1) {
                if(x[0] == y[0]) sum += bc[x[0]].yy.yy;
                else sum += (bc[x[0]].yy.yy + bc[y[0]].yy.yy);
            }
            else if(x.size()==1 && y.size()>=1) {
                if(x[0] == y[0]) sum += (bc[x[0]].yy.yy + bc[y[1]].yy.yy);
                else sum += (bc[x[0]].yy.yy + bc[y[0]].yy.yy);
            }
            else if(x.size()>=1 && y.size()==1) {
                if(x[0] == y[0]) sum += (bc[y[0]].yy.yy + bc[x[1]].yy.yy);
                else sum += (bc[x[0]].yy.yy + bc[y[0]].yy.yy);
            }
            else {
                if(x[0] == y[0]) sum += (bc[x[0]].yy.yy + bc[min(x[1],y[1])].yy.yy);
                else sum += (bc[x[0]].yy.yy + bc[y[0]].yy.yy);
            }
            
            cay = nay, cax = nax;
            cby = nby, cbx = nbx;
        }

        cout<<'#'<<k<<' '<<sum<<'\n';
    }
}