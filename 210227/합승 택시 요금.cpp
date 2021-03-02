#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dist[201][201];
#define INF 10000000
void setting(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
}
void floyd(int n)
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	setting(n);
	for (const auto& fare : fares) {
		dist[fare[0]][fare[1]] = fare[2];
		dist[fare[1]][fare[0]] = fare[2];
	}
	floyd(n);
	answer = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++)
		answer = min(dist[s][i] + dist[i][a] + dist[i][b], answer);
	return answer;
}