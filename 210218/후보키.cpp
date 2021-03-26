#include <bits/stdc++.h>

using namespace std;

bool key_able(vector<int> &answer, int now) {
	for (int i = 0; i < answer.size(); i++) {
		if ((answer[i] & now) == answer[i])
			return false;
	}
	return true;
}

bool cmp_key(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int solution(vector<vector<string>> relation) {
	vector<int> answer;
	int asize = relation.front().size();		
	int rsize = relation.size();				

	vector<pair<int, int>> key;				

	for (int i = 0; i < asize; ++i) {
		set<string> s;
		for (int j = 0; j < rsize; ++j)
			s.insert(relation[j][i]);
		key.push_back({ i, s.size() });
	}
	sort(key.begin(), key.end(), cmp_key);			

	for (int i = 1; i < (1 << asize); ++i) {
		int ukey = 1;

		for (int k = 0; k < asize; k++) {
			if (i&(1 << k))
				ukey *= key[k].second;
		}

		if (ukey < rsize || !key_able(answer, i))			
			continue;
		else {			
			set<string> ss;
			for (int j = 0; j < rsize; ++j) {
				string t = "";
				for (int k = 0; k < asize; k++) {
					if (i&(1 << k))
						t += relation[j][key[k].first];
				}
				ss.insert(t);
			}
			if (ss.size() == rsize)
				answer.push_back(i);
		}
	}

	return answer.size();
}