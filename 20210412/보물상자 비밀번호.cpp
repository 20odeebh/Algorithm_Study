#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
vector<int> ans;
vector<int> num;
deque<char> dq;

int t, n, k;
void clear_func();
void input();
void solution();
void get_num(string str);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		input();

		solution();

		ans.push_back(num[k - 1]);

		clear_func();
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}
void solution()
{
	int num_len = n / 4;

	for (int i = 1; i <= n; ++i)
	{
		string temp = "";
		for (int k = 0; k < num_len; ++k)
		{
			temp += dq[k];
		}
		get_num(temp);

		char ch = dq.back();
		dq.pop_back();
		dq.push_front(ch);
	}

	sort(num.begin(), num.end(), cmp);

	num.erase(unique(num.begin(), num.end()), num.end());
}
void get_num(string str)// 2진수로 바꾸고 계산
{
	int str_len = str.length(); 
	string temp = "";
	for (int i = str_len-1; i >= 0; --i)
	{
		string tp;
		char ch = str[i];
		switch (ch)
		{
		case '0': tp = "0000"; break;
		case '1': tp = "0001"; break;
		case '2': tp = "0010"; break;
		case '3': tp = "0011"; break;
		case '4': tp = "0100"; break;
		case '5': tp = "0101"; break;
		case '6': tp = "0110"; break;
		case '7': tp = "0111"; break;
		case '8': tp = "1000"; break;
		case '9': tp = "1001"; break;
		case 'A': tp = "1010"; break;
		case 'B': tp = "1011"; break;
		case 'C': tp = "1100"; break;
		case 'D': tp = "1101"; break;
		case 'E': tp = "1110"; break;
		case 'F': tp = "1111"; break;
		}

		int tp_len = tp.length();

		for (int k = tp_len - 1; k >= 0; --k) temp += tp[k];
	}
	int sum = 0;
	int temp_len = temp.length();
	int idx = 1;
	for (int i = 0; i < temp_len; ++i)
	{
		sum += (int(temp[i] - '0') * idx);
		idx *= 2;
	}
	num.push_back(sum);
}
void clear_func()
{
	dq.clear();
	num.clear();
}
void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		char ch;
		cin >> ch;
		dq.push_back(ch);
	}
}