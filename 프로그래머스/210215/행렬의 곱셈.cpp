#include <bits/stdc++.h>
using namespace std;
//n1행,  m2열 , m1개의 갯수 곱셈 반복
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int n1 = arr1.size(), m1 = arr1[0].size();
	int n2 = arr2.size(), m2 = arr2[0].size();
	for (int i = 0; i < n1; i++) {
		vector<int> vtemp;
		for (int j = 0; j < m2; j++) {
			int temp = 0;
			for (int k = 0; k < m1; k++) {
				temp += arr1[i][k] * arr2[k][j];
			}
			vtemp.push_back(temp);
		}
		answer.push_back(vtemp);
	}
	return answer;
}