#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, k;
int posx, posy, curage;
int a[11][11];
int b[11][11];
int c[11][11];
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1 ,0 ,1,-1,1,-1,0,1 };
struct Tree {
	int y;
	int x;
	int age;
	int life = 1;
};
int cnt = 0;
vector<Tree>tree[11][11];
void spring();
void summer();
void fall();
void winter();
void print()
{
	cout << "\n==\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << tree[i][j].size() << ' ';
		}
		cout << '\n';
	}
}
void solve() {
	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int t_size = tree[y][x].size();
			cnt += t_size;
		}
	}
}
int main() {
	Tree temp;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> b[y][x];
			a[y][x] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> temp.y >> temp.x >> temp.age;
		tree[temp.y][temp.x].push_back({ temp.y,temp.x,temp.age,1 });
	}
	solve();
	cout << cnt;
}
bool cmp(Tree a, Tree b) {
	return a.age < b.age;
};
void spring() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int t_size = tree[y][x].size();
			if (t_size == 0)continue;
			sort(tree[y][x].begin(), tree[y][x].end(), cmp);
			/*for (int i = 0; i < t_size; i++)
			{
				if (tree[y][x][i].life == 1)
				{
					if (a[tree[y][x][i].y][tree[y][x][i].x] >= tree[y][x][i].age)
					{
						a[tree[y][x][i].y][tree[y][x][i].x] -= tree[y][x][i].age;
						tree[y][x][i].age++;
					}

					else
					{
						tree[y][x][i].life = 0;
					}
				}
			}*/
			int temp_idx = -1;
			for (int i = 0; i < t_size; ++i)
			{
				int cur_age = tree[y][x][i].age;

				if (a[y][x] >= cur_age)
				{
					a[y][x] -= cur_age;
					tree[y][x][i].age++;
				}
				else
				{
					temp_idx = i;
					break;
				}
			}

			if (temp_idx == -1) continue; // 영양분을 못먹은 경우가 없으면 패스
			for (int i = temp_idx; i < t_size; ++i)
			{
				c[y][x] += (tree[y][x][i].age / 2); //여기서 c는 임시적 죽은나무 보관장소 (여름에 a에 붙여줄 예정)
			}
			tree[y][x].erase(tree[y][x].begin() + temp_idx, tree[y][x].end()); // 삭제
		}
	}
}
void summer() {
	vector<Tree>temp;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			/*int t_size = tree[y][x].size();
			for (int i = 0; i < t_size; i++) {
				if (tree[y][x][i].life == 0) {
					a[tree[y][x][i].y][tree[y][x][i].x] += (tree[y][x][i].age / 2);
					tree[y][x][i].age = 0;
				}
				else {
					temp.push_back(tree[y][x][i]);
				}
			}
			tree[y][x] = temp;
			temp.clear();*/
			a[y][x] += c[y][x];
			c[y][x] = 0;
		}
	}
}
void fall() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			int t_size = tree[y][x].size();
			if (t_size == 0) continue;
			for (int i = 0; i < t_size; i++) {
				if (tree[y][x][i].life == 1) {
					if (tree[y][x][i].age % 5 == 0) {
						for (int j = 0; j < 8; j++) {
							int nx = dx[j] + x;
							int ny = dy[j] + y;
							if (ny > n || nx > n || ny < 1 || nx < 1)continue;
							//tree[y][x].push_back({ ny,nx,1,1 });
							tree[ny][nx].push_back({ ny,nx,1,1 });
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			a[y][x] += b[y][x];
		}
	}
}