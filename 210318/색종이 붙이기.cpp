#include <bits/stdc++.h>

using namespace std;

int m[10][10], color[6], ret=30; 
bool chk[10][10];

bool check(int y, int x, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(!m[y+i][x+j]){
                return false;
            }
        }
    }
    return true;
}

void go(int y, int x ,int size, int t){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            m[y+i][x+j]=t;
        }
    }
}

void dfs(int y, int x, int cnt){    
    while(m[y][x]==0){
        if(++x>=10){
            if(++y>=10){
                ret = min(ret,cnt);
                return;
            }
            x=0;
        }
    }
    
    if(ret <= cnt)    return;
    
    for(int s=5; s>0; s--){
        if(y+s>10|| x+s>10|| color[s]==5) continue;
        
        if(check(y,x,s)){
            go(y,x,s,0);
            color[s]++;
            dfs(y,x,cnt+1);
            go
                (y,x,s,1);
            color[s]--;
        }
    }
}

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>m[i][j];
        }
    }

    dfs(0,0,0);
    if(ret==30)  ret=-1;
    cout<<ret;
}
