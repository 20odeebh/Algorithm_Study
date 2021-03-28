#include<iostream>
#include<string>
using namespace std;
string str, bomb;
char ans[1000001];
int str_len = str.length();
int bomb_len = bomb.length();

bool isMatching(int s);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str >> bomb;
	str_len = str.length();
	bomb_len = bomb.length();

	int ans_length = 0;

	for (int i = 0; i < str_len; ++i)
	{
		ans[ans_length] = str[i];
		++ans_length;

		if (ans_length - bomb_len >= 0)
		{
			if (isMatching(ans_length - bomb_len))
			{
				ans_length -= bomb_len;
			}
		}
	}
	ans[ans_length] = '\0';

	if (!ans_length) cout << "FRULA" << '\n';
	else cout << ans << '\n';
	return 0;
}
bool isMatching(int s)
{

	for (int i = s; i < s + bomb_len; ++i) {

		if (ans[i] != bomb[i - s]) {
			return false;
		}
	}
	return true;
}