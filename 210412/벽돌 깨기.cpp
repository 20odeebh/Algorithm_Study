#include<vector>
#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

int n, w, h, org[17][17], map[17][17], Min = 987654321, dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };
bool vis[17][17];

struct Info {
    pii pos;
    int dis;
};
 
queue<Info> bomb;
vector<int> dropCol;
queue<pii> emp;

bool check() {
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] != 0) return false;
        }
    }
    return true;
}

void pick(int k) {
    if (k == n) {
        for (int i = 0; i < dropCol.size(); i++) {
            int c = dropCol[i];
			
            for (int r = 0; r < h; r++) {              
                if (map[r][c] == 1 ) {
                    map[r][c] = 0;
                    break;
                }
				
                else if (map[r][c] > 1) {
                    bomb.push({ { r, c }, map[r][c] });
                    vis[r][c] = true;
 
                    while (!bomb.empty()) {
                        Info cur = bomb.front();
                        bomb.pop();
                        
						int dis = cur.dis;
                        map[cur.pos.first][cur.pos.second] = 0;
 
                        for (int j = 1; j < dis; j++) {
                            for (int m = 0; m < 4; m++) {
                                int nr = cur.pos.first + dr[m] * j;
                                int nc = cur.pos.second + dc[m] * j;
                                
                                if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
                                if (map[nr][nc] == 0 || vis[nr][nc]) continue;
                                
								if (map[nr][nc] >= 1) bomb.push({ { nr, nc }, map[nr][nc]});
                                else map[nr][nc] = 0;
                                vis[nr][nc] = true;
                            }
                        }                       
                    }
 
                    for (int i = 0; i < h; i++){
                        for (int j = 0; j < w; j++){
                            vis[i][j] = false;
						}
					}
                    break;
                }                
            }
            
            if (check()) {
                Min = 0;
                return;
            }
            
            for (int allCol = 0; allCol < w; allCol++) {
                for (int r = h - 1; r >= 0; r--) {
                    if (map[r][allCol] == 0) {
                        emp.push({ r, allCol });
                    }
                    else {
                        if (emp.empty()) continue;
                        pii dst = emp.front();
                        emp.pop();
                        map[dst.first][dst.second] = map[r][allCol];
                        map[r][allCol] = 0;
                        emp.push({ r, allCol });
                    }
                }
                while (!emp.empty()) emp.pop();                
            }            
        }
        
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] != 0) cnt++;
                map[i][j] = org[i][j];
            }
        }
		
        if (Min > cnt) Min = cnt;    
        return;
    }
 
    if (Min == 0) return;
    for (int i = 0; i < w; i++) {
        dropCol.push_back(i);
        pick(k + 1);
        dropCol.pop_back();
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> w >> h;
		
        for (int i = 0; i < h; i++){ 
            for (int j = 0; j < w; j++) {
                cin >> org[i][j];
                map[i][j] = org[i][j];
            }
        }
        pick(0);        
        cout << "#" << test_case << ' ' << Min << '\n';
        Min = 987654321;
	}
	return 0;
}
