#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;
map<string, int> Map1, Map2;
map<string, bool> check;
string s1[1000], s2[1000];
bool checkAlpa(char c) {
	if (c >= 'a' && c <= 'z')return true;
	return false;
}
//모두 소문자로 바꾼뒤 맵을 이용하여 각자 2글자씩 카운트를 센후
//분자에는 두 카운터의 min 값 , 분모에는 두 카운터의 max 값을 넣어준후 계산
int solution(string str1, string str2) {
	int answer = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= 'A' && str1[i] <= 'Z')str1[i] += 32;
	}
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] >= 'A' && str2[i] <= 'Z')str2[i] += 32;
	}
	for (int i = 1; i < str1.size(); i++) {
		s1[i] = "";
		if (checkAlpa(str1[i - 1]) && checkAlpa(str1[i])) {
			s1[i] += str1[i - 1]; s1[i] += str1[i];
			Map1[s1[i]]++;
		}
	}
	for (int i = 1; i < str2.size(); i++) {
		s2[i] = "";
		if (checkAlpa(str2[i - 1]) && checkAlpa(str2[i])) {
			s2[i] += str2[i - 1]; s2[i] += str2[i];
			Map2[s2[i]]++;
		}
	}
	check[""] = true;
	double div1 = 0, div2 = 0;
	for (int i = 1; i < str1.size(); i++) {
		if (check[s1[i]]) {
			continue;
		}
		check[s1[i]] = true;
		div1 += min(Map1[s1[i]], Map2[s1[i]]);
		div2 += max(Map1[s1[i]], Map2[s1[i]]);
	}
	for (int i = 1; i < str2.size(); i++) {
		if (check[s2[i]]) {
			continue;
		}
		check[s2[i]] = true;
		div1 += min(Map1[s2[i]], Map2[s2[i]]);
		div2 += max(Map1[s2[i]], Map2[s2[i]]);
	}
	if (div2 == 0.0)return 65536;
	cout << div1 << ' ' << div2 << '\n';
	answer = ((div1 / div2) * 65536.0);
	return answer;
}