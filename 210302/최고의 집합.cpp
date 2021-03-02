#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	int num;
	if (s < n)
		return { -1 };
	while (n != 0) {
		num = s / n;
		answer.push_back(num);
		n--;
		s -= num;
	}
	sort(answer.begin(), answer.end());

	return answer;
}