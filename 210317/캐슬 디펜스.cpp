#include <bits/stdc++.h>

using namespace std;

int N, M, D, m[15][15], tempMap[15][15], ans = -1;

int getDistance(int x, int y, int A) {
    return abs(N - x) + abs(A - y);
}

int attack(int list[3]) {
    bool attacked[15][15] = {};
    
    for (int k = 0; k < 3; k++) {
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tempMap[i][j] == 1) {
                    int d = getDistance(i, j, list[k]);
                    if (d <= D) v.push_back({ d,{j,i} });
                }
            }
        }
        sort(v.begin(), v.end());
        if (!v.empty()) attacked[v[0].second.second][v[0].second.first]=1;
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (attacked[i][j]) {
                count++;
                tempMap[i][j] = 0;
            }
        }
    }
    return count;
}

void move() {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < M; j++) {
            tempMap[i][j] = tempMap[i - 1][j];
        }
    }
    
    for (int j = 0; j < M; j++) {
        tempMap[0][j] = 0;
    }
}

void gameStart(int list[3]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tempMap[i][j] = m[i][j];
        }
    }
    
    int attackCount = 0;
    for (int i = 0; i < N; i++) {
        attackCount += attack(list);
        move();
    }
    ans = max(ans, attackCount);
    return;
}

int main()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                int list[3] = { i,j,k };
                gameStart(list);
            }
        }
    }
    cout << ans;
}
