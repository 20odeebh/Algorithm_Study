#include <bits/stdc++.h>

using namespace std;

string changed(int hour, int minute) {
	string sh, sm;
	if (hour<10) {
		sh = '0';
		sh += hour + '0';
	}
	else
		sh = to_string(hour);
	if (minute<10) {
		sm = '0';
		sm += minute + '0';
	}
	else
		sm = to_string(minute);
	return sh + ':' + sm;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	// 분으로 환산하기 
	int start = 60 * 9;
	// 마지막 셔틀의 출발 시간, 콘은 이 때 버스를 타야 한다.
	int last_shuttle = (n - 1)*t + start;
	sort(timetable.begin(), timetable.end());
	vector<int> together;

	// 그 전 버스에는 조건에 맞는 크루들을 태운다. (최대 m명)
	for (int i = 0; i<n - 1; i++) {
		int tmp_shuttle = start + i*t;
		int cnt = m;
		while (cnt>0 && !timetable.empty()) {
			string k = timetable.front();
			int hour = stoi(k.substr(0, 2));
			int minute = stoi(k.substr(3, 2));
			int total = hour * 60 + minute;
			if (total <= tmp_shuttle) {
				timetable.erase(timetable.begin());
				cnt--;
			}
			else
				break;
		}

	}

	// 현재 콘과 함께 버스를 탈 후보를 together 벡터에 넣는다.
	while (!timetable.empty()) {
		if (together.size() == m)
			break;
		string k = timetable.front();
		int hour = stoi(k.substr(0, 2));
		int minute = stoi(k.substr(3, 2));
		int total = hour * 60 + minute;
		if (total <= last_shuttle) {
			timetable.erase(timetable.begin());
			together.push_back(total);
		}
		else
			break;
	}

	int hour;
	int minute;
	// 꽉찼으면 제일 늦은 크루보다 1분 빨리 도착해야 탈 수 있다.
	if (together.size() == m) {
		int last = together.back();
		last -= 1;
		hour = last / 60;
		minute = last % 60;
	}
	// 그렇지 않으면 버스가 출발하는 시간에 딱 맞춰서 도착해도 된다.
	else {
		hour = last_shuttle / 60;
		minute = last_shuttle % 60;
	}

	answer = changed(hour, minute);
	return answer;
}