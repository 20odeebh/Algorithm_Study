#include <iostream>

using namespace std;

int R, C, N, v[210][210], dr[4] = { 1,0,-1,0 }, dc[4] = { 0,1,0,-1 };
char m[210][210];

void go(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        
		if (m[nr][nc] == 'O') continue;
        m[nr][nc] = 'O';
        v[nr][nc] = 1;
    }
}
 
int main() {    
    cin >> R >> C >> N;
	
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> m[i][j];
        }
    }
    
    if (N % 2 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << 'O';
            }
            cout << endl;
        }
        return 0;
    }
	
    for (int t = 1; t < N; t+=2) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (m[i][j] == 'O'&&v[i][j] == 0)
                    go(i, j);
            }
        }
 
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (m[i][j] == '.') {
                    m[i][j] = 'O';
                }
                else {
                    m[i][j] = '.';
                }                        
            }
        }
       
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (v[i][j] == 1)
                    v[i][j] = 0;
            }
        }
    }
	
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << m[i][j]; 
        }
        cout << endl;
    }
}
