#include <iostream>

using namespace std;
 
int N,res, dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 }, dir[] = { 2,3,0,1 }, map[102][102];
 
int b[6][4] = {
    {0,0,0,0},
    {2,3,1,0}, 
    {1,3,0,2}, 
    {3,2,0,1},
    {2,0,3,1}, 
    {2,3,0,1} 
};
 
int start(int startX, int startY, int startDir) {
 
    int score = 0;
 
    int x = startX, y = startY, dxr = startDir;
 
    while (true) {
 
        x += dx[dxr], y += dy[dxr];
 
        if (map[x][y] == 0) {
            if (x == startX && y == startY) {
                return score;
            }
        }
 
        else if (map[x][y] == -1) {
            return score;
        }
 
        else if (map[x][y] == -2) {
            dxr = dir[dxr];
            score++;
        }
 
        else if (map[x][y] >= 1 && map[x][y] <= 5) {
            dxr = b[map[x][y]][dxr];
            score++;
        }
 
        else {
            bool isChanged = false;
			
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    
					if ((map[i][j] == map[x][y]) && !(x == i && y == j)) {
                        x = i, y = j;
                        isChanged = true;
                        break;
                    }
					
                }
				
                if (isChanged) {
                    break;
                }
				
            }
        }
    }
}
 
int main() { 
    int test_case;
    int T;
 
    cin >> T;
 
    for (test_case = 1; test_case <= T; test_case++) {
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                map[i][j] = -2;
            }
        }
        res = 0;
 
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> map[i][j];
            }
        }
 
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        if (start(i, j, k) > res) {
                            res = start(i, j, k);
                        }
                    }
                }
            }
        }
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;
}
