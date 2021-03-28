#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<string, bool> Map;
//정렬 후 Map 자료 저장하면서 푼다.
bool solution(vector<string> phone_book) {
	bool answer = true;
	int size = phone_book.size();
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < size; i++) {
		string temp = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			temp += phone_book[i][j];
			if (Map[temp]) {
				answer = false;
				break;
			}
		}
		Map[temp] = true;
	}
	return answer;
}
