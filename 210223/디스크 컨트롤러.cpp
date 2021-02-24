#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct cost_cmp {
	bool operator()(vector<int>& v1, vector<int>& v2)
	{
		return v1[1] > v2[1];
	}
};
struct start_cmp {
	bool operator()(vector<int>& v1, vector<int>& v2)
	{
		return v1[0] > v2[0];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	priority_queue<vector<int>, vector<vector<int>>, cost_cmp> stjf;
	priority_queue<vector<int>, vector<vector<int>>, start_cmp> sf;
	for (const auto& job : jobs)
		sf.push(job);
	int time = 0;
	while (!sf.empty() || !stjf.empty()) {
		if (!sf.empty() && time >= sf.top()[0]) {
			stjf.push(sf.top());
			sf.pop();
			continue;
		}
		if (stjf.size()) {
			time += stjf.top()[1];
			answer += time - stjf.top()[0];
			stjf.pop();
		}
		else {
			time = sf.top()[0];
		}
	}
	answer /= jobs.size();
	return answer;
}