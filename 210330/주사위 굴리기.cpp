#include <iostream>

using namespace std;

int n, m, sy, sx, k;
int a[20][20], dice[6], dy[] = { 0, 0, -1, +1 }, dx[] = { +1, -1, 0, 0 };

void move(int dir) {
    int ndice[6];
    switch (dir)
    {
    case 0:
        ndice[0] = dice[0];
        ndice[5] = dice[1];
        ndice[2] = dice[2];
        ndice[4] = dice[3];
        ndice[1] = dice[4];
        ndice[3] = dice[5];
        break;

    case 1:
        ndice[0] = dice[0];
        ndice[4] = dice[1];
        ndice[2] = dice[2];
        ndice[5] = dice[3];
        ndice[3] = dice[4];
        ndice[1] = dice[5];
        break;

    case 2:
        ndice[3] = dice[0];
        ndice[0] = dice[1];
        ndice[1] = dice[2];
        ndice[2] = dice[3];
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        break;

    case 3:
        ndice[1] = dice[0];
        ndice[2] = dice[1];
        ndice[3] = dice[2];
        ndice[0] = dice[3];
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        break;

    default:
        break;
    }

    for (int i = 0; i < 6; ++i) {
        dice[i] = ndice[i];
    }
}

int main()
{
    cin>> n >> m >> sy >> sx >> k;

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            cin>>a[y][x];
        }
    }

    int dir;
    for (int i = 0; i < k; ++i) {
        cin >> dir;
        --dir;

        int ny = sy + dy[dir];
        int nx = sx + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
            continue;
        }

        move(dir);

        if (a[ny][nx] == 0) {
            a[ny][nx] = dice[3];
        }
        else {
            dice[3] = a[ny][nx];
            a[ny][nx] = 0;
        }
        sy = ny;
        sx = nx;

        cout<<dice[1]<<"\n";
    }
}
