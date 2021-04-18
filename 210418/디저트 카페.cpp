#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
 
int t,n,map[25][25],v[101],ans,sx,sy, dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};
 
void go(int x,int y,int l,int d,int c){
    if(c>=5) return;
	
    v[map[x][y]]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
		
        if(nx==sx && ny==sy && l>=4 && c>=3){ 
            ans=max(ans,l);
            v[map[x][y]]=false;
            return;
        }
        if(nx<0 || nx>=n || ny<0 || ny>=n || v[map[nx][ny]]) continue;
        go(nx,ny,l+1,i,i==d?c:c+1);
    }
    v[map[x][y]]=false;
}
 
int main(){
    cin>> t;
    
	for(int T=1;T<=t;T++){
        cin>>n;
		
        for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> map[i][j];
			}
		}
        ans=-1;		
        for(int i=0;i<n;i++){ 
			for(int j=0;j<n;j++){
            sx=i, sy=j;
			go(i,j,1,-1,0);
			}
		}
        printf("#%d %d\n",T,ans);
    }
    return 0;
}
