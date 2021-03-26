#include <bits/stdc++.h>

using namespace std;

char lastword;
vector<string> list;


vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	for (int i = 0; i < words.size(); i++) {
		string t = words[i];
		
		for (string t:list) {
			if (t == words[i]) {
				answer.push_back(i%n+1);
				answer.push_back(i /n+1);
				return answer;
			}
		}
		
		if (lastword != t[0] && lastword!=NULL) {
			answer.push_back(i % n + 1);
			answer.push_back(i / n+1);
			return answer;
		}

		list.push_back(words[i]);
		lastword = t[t.length()-1];
	}
	answer.push_back(0);
	answer.push_back(0);

	return answer;
}
