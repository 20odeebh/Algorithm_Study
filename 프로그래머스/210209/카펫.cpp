#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
//모든 약수를 구하면서 brown의 갯수를 구하고
//일치하면 정답
vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int y2 = sqrt(yellow);
	for (int i = 1; i <= y2; i++) {
		if (yellow % i == 0) {
			int r = i, c = yellow / i;
			int sum = ((c+2) * 2) + r * 2;
			if (sum == brown) {
				answer.push_back(c+2);
				answer.push_back(r+2);
				return answer;
			}
		}
		
	}
	return answer;
}
