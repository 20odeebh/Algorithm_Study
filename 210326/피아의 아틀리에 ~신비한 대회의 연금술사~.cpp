#include<bits/stdc++.h>

using namespace std;

int n,ans;
char cost[256];
vector<material> materials;

struct material {
  int x[4][4];
  char c[4][4];
  
  void turn() {
    for(int i = 0; i < 4; i++) {
      for(int j = i; j < 4; j++) {
        swap(x[i][j], x[j][i]);
        swap(c[i][j], c[j][i]);
      }
    }
	
    for(int i = 0; i < 4; i++) {
      reverse(x[i], x[i]+4);
      reverse(c[i], c[i]+4);
    }
	
  }
};



void go(int k, vector<bool> live, vector<vector<int>> X, vector<vector<char>> C) {
  if(k == 3) {
    int ret = 0;
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        ret += cost[C[i][j]] * X[i][j];
      }
    }
    if(ans < ret) ans = ret;
    return;
  
  
  for(int x = 0; x < n; x++) if(live[x]) {
    vector<bool> na = live; na[x] = false;
    for(int rep = 0; rep < 4; rep++) {
      for(int p = 0; p < 2; p++) {
        for(int q = 0; q < 2; q++) {
		
          vector<vector<int>> nx = X;
          vector<vector<char>> nc = C;
		  
          for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
              nx[p+i][q+j] += materials[x].x[i][j];
			  
              if(nx[p+i][q+j] < 0) nx[p+i][q+j] = 0;
              if(nx[p+i][q+j] > 9) nx[p+i][q+j] = 9;
              if(materials[x].c[i][j] != 'W') nc[p+i][q+j] = materials[x].c[i][j];
            }
          }
          go(k+1, na, nx, nc);
        }
      }
      materials[x].turn();
    }
  }

}

int main(){
  cin>>n;
  for(int k = 0; k < n; k++) {
    material now;
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        cin>>now.x[i][j];
      }
    }
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        char tmp[5];
        cin>>tmp;
        now.c[i][j] = tmp[0];
      }
    }
    materials.pushkback(now);
  }

  cost['R'] = 7;
  cost['G'] = 3;
  cost['B'] = 5;
  cost['Y'] = 2;
  go(0, vector<bool>(n, true), vector<vector<int>>(5, vector<int>(5, 0)), vector<vector<char>>(5, vector<char>(5, 'W')));

  cout<<ans;
}
