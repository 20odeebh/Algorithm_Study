#include <bits/stdc++.h>

using namespace std;

struct INFO{
    bool bo, ki;
};
int N;

INFO arr[101][101];

// 기둥이 설치될 수 있는지 확인
bool canKi(int x, int y){
	// 1. 땅
    if(y==0)
        return true;
    // 2. 아래에 기둥이 있을 때
	if(y-1>=0 && arr[x][y-1].ki)
        return true;
	// 3. 세워지는 자리에 보가 있을 때
    if(x-1>=0 && arr[x-1][y].bo)
        return true;
    if(arr[x][y].bo)
        return true;      
    return false;
}

// 보가 설치될 수 있는지 확인 
bool canBo(int x, int y){
	// 1. 기둥이 세워져있을 때
    if(y-1>=0 && arr[x][y-1].ki)
        return true;
    if(x+1<=N && y-1>=0 && arr[x+1][y-1].ki)
        return true;
	// 2. 양 옆에 보가 있을 때
    if(x-1>=0 && x+1<=N && arr[x-1][y].bo && arr[x+1][y].bo)
         return true;
    return false;
}

// 중요: 삭제할 때 다시 식 세우지 말고, 이미 삭제했다고 표시하고 나머지 기둥과 보에 대해서
// 설치될 수 있는 경우인지 확인
bool checkAll(){
    // 모든 보와 기둥에 대해서 만족하는지 확인 
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(arr[i][j].ki){
                if(!canKi(i,j))
                    return false;
            }
            if(arr[i][j].bo){
                if(!canBo(i,j))
                    return false;
            }
        }
    }
    return true;
}


void remove_arr(int x, int y, int a){
    // 기둥
    if(a==0){
        arr[x][y].ki=false;
        if(!checkAll())
            arr[x][y].ki=true;
    }
    // 보
    else{
        arr[x][y].bo=false;
        if(!checkAll())
            arr[x][y].bo=true;
    }
}

void build_arr(int x, int y, int a){
    // 기둥
    if(a==0){
        if(canKi(x,y))
            arr[x][y].ki=true;
    }
    // 보
    else{
        if(canBo(x,y))
            arr[x][y].bo=true;
    }
    return;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N=n;
    for(auto &k:build_frame){
        int x = k[0];
        int y = k[1];
        int a = k[2];
        int b = k[3];
        // 삭제
        if(b==0){
            remove_arr(x,y,a);
        }
        // 삽입
        else{
            build_arr(x,y,a);
        }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(arr[i][j].ki){
                //cout << i << ' ' << j << ' ' << 0 << endl;
                answer.push_back({i,j,0});
            }
            if(arr[i][j].bo){
                //cout << i << ' ' << j << ' ' << 1 << endl;
                answer.push_back({i,j,1});
            }
        }
    }
    
    return answer;
}