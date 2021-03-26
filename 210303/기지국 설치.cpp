#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0, start = 0;
	int dis = w * 2 + 1;
	
	sort(stations.begin(), stations.end());

	for (int i = 0; i<stations.size(); i++) {
		int left = stations[i] - 1 - w;
		int right = stations[i] - 1 + w;

		if (start >= left && start <= right) {
			start = right+1;
			continue;
		}

		int div = (left - start)/dis;
		int rest = (left - start) % dis;
		
		if (rest > 0) {
			div += 1;
		}
		answer += div;
		start = right + 1;
	}
	
	if (start < n) {
		int div = (n - start) / dis;
		int rest =( n - start) % dis;
		if (rest > 0)
			div += 1;
		answer += div;
	}
	return answer;
}