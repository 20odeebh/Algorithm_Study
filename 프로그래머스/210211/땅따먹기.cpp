#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int d[100001][4];
//위치별로 최댓값 저장
//다이나믹 프로그래밍
//이전과 같은 위치를 제외한 모든 곳에서 최댓값 비교
int solution(vector<vector<int> > land)
{
	int answer = 0;
	int size = land.size();
	for (int i = 0; i < 4; i++) {
		d[0][i] = land[0][i];
	}
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < 4; j++) {
			d[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				if (k == j)continue;
				d[i][j] = max(d[i][j], d[i - 1][k]);
			}
			d[i][j] += land[i][j];
		}
	}
	int n2 = size - 1;
	for (int i = 0; i < 4; i++) {
		answer = max(answer, d[n2][i]);
	}
	return answer;
}