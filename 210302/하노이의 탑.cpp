#include <string>
#include <vector>

using namespace std;
void hanoi(int num, int start, int to, int mid, vector<vector<int>>& answer)
{
	if (num == 1) {
		answer.push_back({ start, to });
		return;
	}
	hanoi(num - 1, start, mid, to, answer);
	answer.push_back({ start, to });
	hanoi(num - 1, mid, to, start, answer);
}
vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	hanoi(n, 1, 3, 2, answer);
	return answer;
}