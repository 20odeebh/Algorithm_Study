#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	
	int currtime = 0;
	int currbus = 1;
	int go = 0;

	int start = 540;
	priority_queue<int, vector<int>, greater<int>> wait;		

	for (int i = 0; i < timetable.size(); i++) {
	
		int hour = (timetable[i][0] - '0') * 10 + (timetable[i][1]-'0');
		int minute = (timetable[i][3] - '0') * 10 + (timetable[i][4] - '0');
		wait.push(hour * 60 + minute);
	}

	
	while (currbus<=n) {
		if (wait.empty()) {		
			currtime = 540 + t * (n - 1);		
			break;
		}
		else {		
			if (start < wait.top()) {		
				if (currbus == n) {			
					currtime = 540 + t * (n - 1);
					break;
				}
				start += t; 
				++currbus;
				go = 0;
			}
			else {							
				if (go == m - 1 && currbus == n) {		
					currtime = wait.top() - 1;		
					break;
				}
				wait.pop();
				++go;
			}
		}

		if (go == m) {		
			start += t;
			++currbus;
			go = 0;
		}
	}

	if (currtime / 60 >= 10) 	
		answer += to_string(currtime / 60);
	else {
		answer += "0";
		answer += to_string(currtime / 60);
	}
	answer += ":";

	if (currtime % 60 >= 10) 
		answer += to_string(currtime % 60);
	else {
		answer += "0";
		answer += to_string(currtime % 60);
	}

	return answer;
}
