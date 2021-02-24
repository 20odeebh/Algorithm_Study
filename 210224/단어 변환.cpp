#include <string>
#include <vector>
#include <queue>

using namespace std;
int visit[50];
bool IsChange(const string& begin, const string& target)
{
	int len = begin.length(), cnt = 0;
	for (int i = 0; i < len; i++) {
		if (begin[i] != target[i]) {
			cnt++;
		}
	}
	if (cnt <= 1)
		return true;
	else
		return false;
}
void bfs(const string& begin, const string& target, const vector<string>& words)
{
	queue<pair<string, int>> q;
	q.push({ begin, 1 });
	string cur;
	int dist;
	while (!q.empty()) {
		cur = q.front().first;
		dist = q.front().second;
		q.pop();
		for (int i = 0; i < words.size(); i++) {
			if (visit[i] == 0 && IsChange(cur, words[i])) {
				visit[i] = dist;
				q.push({ words[i], dist + 1 });
			}
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0, target_idx = -1;
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
		if (*it == target) {
			target_idx = it - words.begin();
			break;
		}
	}
	if (target_idx == -1)
		return 0;
	bfs(begin, target, words);
	answer = visit[target_idx];
	return answer;
}