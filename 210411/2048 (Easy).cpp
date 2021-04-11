#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, ans, a[21][21];
queue<int> q;

int findMax(int a[21][21]) {
    int num = 0;
    
	for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) {
            if (a[i][j] <= num) continue;
            num = max(num, a[i][j]);
        }
    return num;
}

void go_up(int a[][21]) {
    bool c[21][21] = { false, };
    
	for (int j = 0; j<n; j++) {
        for (int i = 1; i<n; i++) {
            if (a[i][j] == 0) continue;
            int num = a[i][j];
            for (int k = i - 1; k >= 0; k--) {
                if (a[k][j] == 0) continue;
                if (a[k][j] != num || c[k][j]) break;
                a[k][j] *= 2;
                c[k][j] = true;
                a[i][j] = 0;
                break;
            }
        }
    }
    
	for (int j = 0; j<n; j++) {
        for (int i = 0; i<n; i++) {
            if (a[i][j] == 0) continue;
            q.push(a[i][j]);
            a[i][j] = 0;
        }
        
		int index = 0;
        while (!q.empty()) {
            a[index++][j] = q.front(); q.pop();
        }
    }
}

void go_down(int a[][21]) {
    bool c[21][21] = { false, };
    
	for (int j = 0; j<n; j++) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i][j] == 0) continue;
            int num = a[i][j];
            for (int k = i + 1; k<n; k++) {
                if (a[k][j] == 0) continue;
                if (a[k][j] != num || c[k][j]) break;
                a[k][j] *= 2;
                c[k][j] = true;
                a[i][j] = 0;
            }
        }
    }
	
    for (int j = 0; j<n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == 0) continue;
            q.push(a[i][j]);
            a[i][j] = 0;
        }
        int index = n - 1;
        while (!q.empty()) {
            a[index--][j] = q.front(); q.pop();
        }
    }
}

void go_left(int a[][21]) {
    bool c[21][21] = { false, };
    
	for (int i = 0; i<n; i++) {
        for (int j = 1; j<n; j++) {
            if (a[i][j] == 0) continue;
            int num = a[i][j];
            for (int k = j - 1; k >= 0; k--) {
                if (a[i][k] == 0) continue;
                if (a[i][k] != num || c[i][k]) break;
                a[i][k] *= 2;
                c[i][k] = true;
                a[i][j] = 0;
                break;
            }
        }
    }
    
	for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (a[i][j] == 0) continue;
            q.push(a[i][j]);
            a[i][j] = 0;
        }
        int index = 0;
        while (!q.empty()) {
            a[i][index++] = q.front(); q.pop();
        }
    }
}

void go_right(int a[][21]) {
    bool c[21][21] = { false, };
    
	for (int i = 0; i<n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (a[i][j] == 0) continue;
            int num = a[i][j];
            for (int k = j + 1; k<n; k++) {
                if (a[i][k] == 0) continue;
                if (a[i][k] != num || c[i][k]) break;
                a[i][k] *= 2;
                c[i][k] = true;
                a[i][j] = 0;
                break;
            }
        }
    }
    
	for (int i = 0; i<n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 0) continue;
            q.push(a[i][j]);
            a[i][j] = 0;
        }
        int index = n - 1;
        while (!q.empty()) {
            a[i][index--] = q.front(); q.pop();
        }
    }
}

void go(int cnt, int a[21][21]) {
    if (cnt == 5) {
        ans = max(ans, findMax(a));
        return;
    }
	
    int map[21][21] = { 0, };
 
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            map[i][j] = a[i][j];
 
    go_up(map);
    go(cnt + 1, map);
     
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            map[i][j] = a[i][j];
     
    go_down(map);
    go(cnt + 1, map);
     
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            map[i][j] = a[i][j];
     
    go_left(map);
    go(cnt + 1, map);
     
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            map[i][j] = a[i][j];
     
    go_right(map);
    go(cnt + 1, map);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
	
	go(0, a);
    cout << ans << endl;
}
