#include <bits/stdc++.h>

using namespace std;

struct p {
    int x, y;
};

int n = 12, m = 6, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char a[12][7];
bool ch[12][7];

void fall() {
    for (int j=0; j<m; j++) {
        for (int i=n-1; i>=0; i--) {
            if (a[i][j] == '.') continue;
            for (int k=n-1; k>=i; k--) {
                if (a[k][j] == '.') {
                    a[k][j] = a[i][j];
                    a[i][j] = '.';
                }
            }
        }
    }
}

bool bfs(int i, int j, char c) {
    queue<p> q;
    vector<p> block;
    
	q.push({i, j});
    ch[i][j] = true;
    block.push_back({i, j});

    while (!q.empty()) {
        int x = q.front().x, y = q.front().y; q.pop();
        
		for (int k=0; k<4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (ch[nx][ny] || a[nx][ny] != c) continue;
            
			ch[nx][ny] = true;
            block.push_back({nx, ny});
            q.push({nx, ny});
        }
    }
   
    if ((int)block.size() >= 4) {
        for (auto k : block) a[k.x][k.y] = '.';
        return true;
    } else return false;
}

bool crash() {   
    bool crashed = false;
    memset(ch, false, sizeof(ch));
    
	for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            if (ch[i][j] || a[i][j] == '.') continue;
            if (bfs(i, j, a[i][j])) crashed = true;
        }
    }
    return crashed;
}

void sol() {
    int ans = 0;
    while (crash()) {
        fall();
        ans += 1;
    }
    cout<<ans;
}

int main() {
    for (int i=0; i<n; i++){ 
        cin>>a[i];
    }
    sol();
}
