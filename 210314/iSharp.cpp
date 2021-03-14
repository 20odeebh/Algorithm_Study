#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>
#include <memory.h>
#include <unordered_map>

using namespace std;
// 50분

bool IsAlpha(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= 'A' && ch <= 'Z')
		return true;
	return false;
}

int main() {
	string str;
	getline(cin, str);
	string basic;
	int idx = 0;
	while (1) {
		if (str[idx]==' ') {
			break;
		}
		basic += str[idx++];
	}
	// 참조, 배열, 포인터 순인듯
	string tmp;
	
	for (int i = idx + 1; i < str.size();i++) {
		if (str[i] == ',' || str[i] == ';') {
			string alpa;
			string rev;
			for (int j = 0; j < tmp.size(); j++) {
				if (IsAlpha(tmp[j])) {
					alpa += tmp[j];
				}
				else {
					if (tmp[j] == '[') {
						rev = "[]" + rev;
						j++;
					}
					else
						rev = tmp[j] + rev;
				}
			}
			i++;
			cout << basic + rev << ' ' << alpa << ";\n";
			tmp.clear();
		}
		else
			tmp += str[i];
	}

}s