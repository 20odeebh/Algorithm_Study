#include <bits/stdc++.h>

using namespace std;

int main(){
	deque<char> dq;
	string main_str, find_str;
	cin >> main_str >> find_str;
	
	for (char ch : main_str) {
		bool check = true;
		dq.push_back(ch);

		if (ch != dq.back() || dq.size() < find_str.size()) continue;

		for (int i = 0; i < find_str.size(); i++) {
			if (dq[dq.size() - i - 1] != find_str[find_str.size() - i - 1]) {
				check = false;
				break;
			}
		}

		if (check) {
			for (int i = 0; i < find_str.size(); i++) dq.pop_back();
		}
	}

	if (dq.size() == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
		}
	}	
	cout << "\n"; 
}
