#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	map<int, int> m;
	int num;
	map<int, int>::iterator it;
	for (const auto& op : operations) {
		if (op[0] == 'I') {
			num = stoi(op.substr(2));
			m[num]++;
		}
		else {
			if (m.size() == 0)
				continue;

			if (op[2] == '1')
				it = --m.end();
			else
				it = m.begin();

			m[it->first]--;
			if (m[it->first] == 0)
				m.erase(it);
		}
	}
	if (m.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}
	it = --m.end();
	answer.push_back(it->first);
	it = m.begin();
	answer.push_back(it->first);
	return answer;
}