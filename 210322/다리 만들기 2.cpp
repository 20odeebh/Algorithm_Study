#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, k, map[11][11], bridge[7][7], parent[7], dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
bool visited[11][11];		

vector<pair<int, int>> island_start[7];		
vector<pair<pair<int, int>, int>> bridge_total;	

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	return a.second < b.second;
}

void changeNumber(int i, int j, int k);
void dfs(int x, int y, int dir, int cnt, int start);
void getLength(int start);
int parentCheck(int node);
void sameParent(int a, int b);
bool check();

void input(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
		}
	}
}

void changeIsland(){
	k = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1 && visited[i][j]==false) {changeNumber(i, j, k); k++;}
		}
	}
	k--;
}

void changeNumber(int i, int j, int k){
	if(i<0 || j<0|| i>=N || j>=M) return;
	if(visited[i][j]==true || map[i][j]==0) return;

	map[i][j] = k;
	island_start[k].push_back({i, j});
	visited[i][j] = true;

	changeNumber(i+1, j, k);
	changeNumber(i, j+1, k);
	changeNumber(i-1, j, k);
	changeNumber(i, j-1, k);
}

void getBridge(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			bridge[i][j] = 987654321;
		}
	}
	for(int i=1;i<=k;i++){
		getLength(i);
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(bridge[i][j]!= 987654321) bridge_total.push_back({{i, j}, bridge[i][j]});
		}
	}
}

void getLength(int start){
	for(int i = 0 ; i < island_start[start].size(); i++){
		int x = island_start[start][i].first, y = island_start[start][i].second;
		for (int dir = 0; dir<4; dir++){
			dfs(x, y, dir, 0, start);
		}
	}
}

void dfs(int x, int y, int dir, int cnt, int start){
	int nx = x + dx[dir], ny = y + dy[dir];
	if(nx < 0 || ny < 0 || nx >= N || ny >= M) return;

	int now = map[nx][ny];

	if (now == 0) dfs(nx, ny, dir, cnt+1, start);
	else if(now != start){
		if(cnt > 1){
			if(bridge[start][now] > cnt){
				bridge[start][now] = cnt;
				bridge[now][start] = cnt;
			}
			return;
		}
	}
}

void getMin(){
	int answer = 0;

	sort(bridge_total.begin(), bridge_total.end(), comp);
	
	for(int i=1;i<=k;i++) parent[i] = i;
	for(int i=0;i<bridge_total.size();i++){	
		int start = bridge_total[i].first.first, end = bridge_total[i].first.second;
		int length = bridge_total[i].second;
		if(parentCheck(start) != parentCheck(end)){
			answer += length;
			sameParent(start, end);
		}
	}

	if(check() == true) cout << answer << "\n";
	else cout << "-1\n";
}

bool check(){
	bool answer = true; int tmp = parentCheck(1);
	for(int i=2;i<=k;i++){
		if(tmp != parentCheck(i))
			return false;
		tmp = parentCheck(i);
	}
	return answer;
}

int parentCheck(int node){
	if(parent[node]==node)	return node;
	return parent[node] = parentCheck(parent[node]);
}

void sameParent(int a, int b){
	parent[parent[a]] = parent[b];
}

void print(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}

int main(){
	input();				
	changeIsland();		
	getBridge();			
	getMin();	
}
