#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N, K;
string str;
unordered_map<string, int> m;
vector<long long> v;
void make_pwd(string str)
{
	string pwd;
	int size = str.length();
	int cnt = str.length() / 4;
	//회전
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < 4; j++) {
			pwd = str.substr((size / 4) * j, size / 4);
			m[pwd]++;
		}
		char temp = str[size - 1];
		str.insert(0, 1, temp);
		str.pop_back();
	}
}
long long hex2dec(const string& str)
{
	long long sum = 0, digit;
	for (int i = str.length() - 1; i >= 0; i--) {
		digit = pow(16, str.length() - i - 1);
		if ('A' <= str[i] && str[i] <= 'Z') {
			sum += (str[i] - 'A' + 10) * digit;
		}
		else {
			sum += (str[i] - '0') * digit;
		}
	}
	return sum;
}
long long get_result()
{
	for (const auto& it : m)
		v.push_back(hex2dec(it.first));
	sort(v.begin(), v.end(), greater<long long>());
	return v[K - 1];
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		v.clear();
		m.clear();
		cin >> N >> K;
		cin >> str;
		make_pwd(str);
		printf("#%d %lld\n", test_case, get_result());
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}