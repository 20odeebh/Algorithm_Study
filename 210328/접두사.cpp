#include <bits/stdc++.h>

using namespace std;

int n,res;
vector<str> s;

struct str {
	string s;
	int len;
	str(string ss, int l) {
		s = ss;
		len = l;
	}

	bool operator<(const str &d) {
		return len < d.len;
	}
};
int main() {	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		s.push_back(str(tmp, tmp.size()));
	}
	
	sort(s.begin(), s.end());
	
	for (int i = 0; i < s.size(); i++) {
		bool prefix = false;
		for (int j = i + 1; j < s.size(); j++) {
			if (s[j].s.find(s[i].s) == 0 ) {
				 prefix = true;
			}
		}
		if (prefix) res++;
	}
	cout << n-res << "\n";
}
