#include <bits/stdc++.h>

using namespace std;

int arr[102][102][102];

int m = 0, n = 0, cnt = 0, h = 0;
queue<int> x, y,z;

void find( ) {

	for (int k = 1; k <= h; k++)
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j][k] == 1) { 
        x.push(j);
        y.push(i);
        z.push(k); 
        }
			}
		}
}

int search(int sized) {
	if (sized == 0) return 0;
  
	while (sized--) {
		int x_x = x.front();
		int y_y = y.front();
		int z_z = z.front();
    
		if (arr[y_y - 1][x_x][z_z] == 0) y.push(y_y - 1), x.push(x_x ),z.push(z_z), arr[y_y - 1][x_x][z_z] =1;
		if (arr[y_y + 1][x_x][z_z] == 0) y.push(y_y + 1), x.push(x_x), z.push(z_z), arr[y_y + 1][x_x][z_z] = 1;
		if (arr[y_y][x_x - 1][z_z] == 0) y.push(y_y), x.push(x_x-1), z.push(z_z), arr[y_y ][x_x-1][z_z] = 1;
		if (arr[y_y][x_x + 1][z_z] == 0) y.push(y_y), x.push(x_x + 1), z.push(z_z), arr[y_y][x_x + 1][z_z] = 1;
		if (arr[y_y][x_x][z_z - 1] == 0) y.push(y_y), x.push(x_x ), z.push(z_z - 1), arr[y_y][x_x][z_z - 1] = 1;
		if (arr[y_y][x_x][z_z + 1] == 0) y.push(y_y), x.push(x_x), z.push(z_z + 1), arr[y_y][x_x][z_z + 1] = 1;
		x.pop(), y.pop(), z.pop();
	}
	return 1;
}

int search2() {
	for (int k = 1; k <= h; k++)
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				{
					if (arr[i][j][k] == 0 && arr[i - 1][j][k] == -1 && arr[i + 1][j][k] == -1 && arr[i][j - 1][k] == -1 && arr[i][j + 1][k] == -1)
						if (arr[i][j][k - 1] == -1 && arr[i][j][k + 1] == -1)
							return 1;

				}
			}
		}
	return 0;
}

int main(){
	memset(arr, -1, sizeof(int) * 102 * 102 * 102);
	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j][k];
	}

	if (search2() == 1) {
		cout << -1 << '\n';
		return 0;
	}
				
	find();

	while (true) {
		int sd = x.size();
		if (search(sd) == 0) break;
		cnt++;		
	}
		
	cout << cnt-1 << '\n';
}
