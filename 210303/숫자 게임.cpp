#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer,save = 0;
	
	sort(B.begin(), B.end());
	sort(A.begin(), A.end());
	
	
	for (int i = 0; i < A.size(); i++) {
		for (int j = save; j < B.size(); j++) {
			
			if(A[i]<B[j]){
				answer++;
				save = j;
				save++;
				break;
			}
		}
	}
	return answer;
}