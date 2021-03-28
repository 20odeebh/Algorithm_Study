#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<string, long long> Map;
//각각 (1~종류의수)개의 옷을 입는 경우의수를 구해준다.
//이때 안입는다는 선택지를 넣어 다 곱해준후 , 전부 안입는경우의 수 1개를 빼준다.
long long solution(vector<vector<string>> clothes) {
	long long answer = 1;
	long long n = clothes.size();
	for (int i = 0; i < n; i++) {
		Map[clothes[i][1]]++;
	}
	for (auto it = Map.begin(); it != Map.end(); it++) {
		answer *= ((*it).second+1LL);
	}
	answer--;
	return answer;
}
