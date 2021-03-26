#include <bits/stdc++.h>

using namespace std;



int getLength(string start, string end) {
	int sh = stoi(start.substr(0, 2));
	int eh = stoi(end.substr(0, 2));
	
	int sm = stoi(start.substr(3, 2));
	int em = stoi(end.substr(3, 2));
	return (eh * 60 + em) - (sh * 60 + sm);
}

string removeSharp(string m) {
	for (int i = 0; i < m.size() - 1; i++) {
		if (m[i + 1] == '#') {
			m[i] = tolower(m[i]);
			m.erase(m.begin() + i + 1);
			i--;
		}
	}
	return m;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	int answerLen = 0;
	
	m = removeSharp(m);

	for (string info : musicinfos) {
		string start = info.substr(0, 5);
		string end = info.substr(6, 5);
		int len = getLength(start, end);
		
		int nameEnd = info.find(',', 12);
		
		string name = info.substr(12, nameEnd - 12);
		string melody = info.substr(nameEnd + 1);
		melody = removeSharp(melody);
        
        
        if(m.length() > len){
             continue;
        }

		
		while (melody.size() < len) {
			melody += melody;
		}
		melody = melody.substr(0, len);
        
        
		if (melody.find(m) != string::npos) {
			if (answerLen < len) {
				answer = name;
				answerLen = len;
			}
        }
        
	}
	return answer;
}
