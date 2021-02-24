#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	int range = routes[0][1];
	sort(routes.begin(), routes.end());

	for (int i = 0; i < routes.size() - 1; i++) {
		if (range > routes[i][1]) range = routes[i][1];
		if (range < routes[i + 1][0]) {
			range = routes[i + 1][1];
			answer++;
		}
	}
	return answer;
}