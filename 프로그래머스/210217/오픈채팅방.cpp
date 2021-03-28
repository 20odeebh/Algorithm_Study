#include <bits/stdc++.h>
using namespace std;
map<string, string> Map;
vector<vector<string>> record_v;
//최종적으로 Change 하거나 Enter한 아이디의 닉네임을 바꿔준다.
//이때 string,string 형 맵을 사용하여 교체
vector<string> solution(vector<string> record) {
	vector<string> answer;
	int size = record.size();
	for (int i = 0; i < size; i++) {
		vector<string> v;
		string now = "";
		for (int j = 0; j < record[i].size(); j++) {
			if (record[i][j] == ' ') {
				v.push_back(now);
				now = "";
			}
			else {
				now += record[i][j];
			}
		}
		v.push_back(now);
		record_v.push_back(v);
		if (v[0][0] == 'E' || v[0][0] == 'C') {
			Map[v[1]] = v[2];
			continue;
		}
	}
	for (auto v : record_v) {
		if (v[0][0] == 'E') {
			answer.push_back("""" + Map[v[1]] + "님이 들어왔습니다.""");
		}
		else if (v[0][0] == 'L') {
			answer.push_back("""" + Map[v[1]] + "님이 나갔습니다.""");
		}
	}
	return answer;
}