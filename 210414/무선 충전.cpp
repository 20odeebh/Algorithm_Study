#include <queue>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

int dir[5][2] = { {0,0}, { 0,-1 }, {1,0}, {0,1}, {-1,0} };

typedef struct info {
	int apno, energy;
}info;

typedef struct xy {
	int x, y;
}xy;

int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int test;
	cin >> test;
	
	for (int t = 1; t <= test; t++) {
		int A[101], B[101], cnt, ap;		
		vector <info> arr[11][11];

		cin >> cnt >> ap;
		
		for (int i = 0; i < cnt; i++) {
			cin >> A[i];
		}
		
		for (int i = 0; i < cnt; i++) {
			cin >> B[i];
		}
	
		for (int i = 0; i < ap; i++) {
			int stx, sty, s, energy, visit[11][11];
			memset(visit, 0, sizeof(visit));
			
			int TIME = 0;
			cin >> stx >> sty >> s >> energy;
			
			queue <xy>q;
			q.push({ stx,sty });
			visit[stx][sty] = true;
			arr[stx][sty].push_back({ i,energy });

			while (!q.empty()) {
				int size = q.size();
				TIME++;

				while (size--) {
					int fx = q.front().x, fy = q.front().y;
					q.pop();

					for (int d = 1; d <= 4; d++) {
						int nx = fx + dir[d][0];
						int ny = fy + dir[d][1];
						
						if (nx <= 0 || nx > 10 || ny <= 0 || ny > 10)continue;						
						if (visit[nx][ny])continue;
						
						visit[nx][ny] = true;
						q.push({ nx,ny });
						arr[nx][ny].push_back({ i,energy });
					}
				}				
				if (TIME == s)break;

			}			
		}

		int ax = 1, ay = 1;
		int bx = 10, by = 10;
		
		int sum = 0, c = 0;
		while(true){

			int Ad = A[c];
			int Bd = B[c];		
			
			if (arr[ax][ay].size()==0|| arr[bx][by].size() ==0) {
				int maxx = 0;
				
				for (int i = 0; i < arr[ax][ay].size(); i++) {
					maxx = MAX(maxx, arr[ax][ay][i].energy);
				}
				
				for (int i = 0; i < arr[bx][by].size(); i++) {
					maxx = MAX(maxx, arr[bx][by][i].energy);
				}
				
				sum += maxx;
			}

			else {
				int maxx = 0;
				int temp = 0;
				
				for (int i = 0; i < arr[ax][ay].size(); i++) {
					int apA = arr[ax][ay][i].apno;
					int energyA = arr[ax][ay][i].energy;
					
					for (int j = 0; j < arr[bx][by].size(); j++) {
						int apB = arr[bx][by][j].apno;
						int energyB = arr[bx][by][j].energy;
						temp = energyA + energyB;
						
						if (apA == apB)temp /= 2;
						maxx = MAX(maxx, temp);
					}
				}
				sum += maxx;
			}

			if (c >= cnt)break;

			ax += dir[Ad][0], ay += dir[Ad][1];
			bx += dir[Bd][0], by += dir[Bd][1];
			c++;
		}
		cout << "#" << t << " " << sum << '\n';		
	}
}
