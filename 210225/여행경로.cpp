#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visit[10000];
vector<vector<string>> v;
vector<string> path, result;
bool done = false;
void dfs(string str)
{
	if (path.size() == v.size() + 1 && !done) {
		done = true;
		result = path;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (visit[i] == false && v[i][0] == str) {
			visit[i] = true;
			path.push_back(v[i][1]);
			dfs(v[i][1]);
			visit[i] = false;
			path.pop_back();
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end());
	v = tickets;
	path.push_back("ICN");
	for (int i = 0; i < tickets.size(); i++) {
		if (visit[i] == false && tickets[i][0] == "ICN") {
			visit[i] = true;
			path.push_back(tickets[i][1]);
			dfs(tickets[i][1]);
			path.pop_back();
			visit[i] = false;
		}
	}
	answer = result;
	return answer;
}