#include <iostream>

using namespace std;

int N, K, answer, weight = 500, kit[51];
bool visited[51];

void dfs(int count) {
	if (count == N) {
	  answer++;
	}
	else {
		
		for (int i = 0; i < N; i++) {
			if (visited[i] != true) {
				visited[i] = true;
				if (weight + kit[i] - K >= 500) {	
					weight += kit[i] - K;
					dfs(count + 1);
					weight -= kit[i] - K;
					visited[i] = false;
				}
				else
					visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> kit[i];
	}
	dfs(0);
	cout << answer;
}
