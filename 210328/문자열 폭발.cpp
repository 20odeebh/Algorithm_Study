#include <iostream>
#include <string>
using namespace std;
/*
����
1. ��� ���ڿ��� ����, ���� ���ڿ��� ������ ���ڿ� ��
2. ��ġ�ϴ� ���ڰ� �ִٸ�, ���� ���ڿ��� ���̸�ŭ �� �� ���̰� ���ٸ� pop_back
2.1 ��� ���ڿ��� �ε��� ����
*/
int main()
{
	string str, bomb;
	cin >> str >> bomb;
	int idx = 0, bomb_len = bomb.length();
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		result.push_back(str[i]);
		idx++;
		if (result[idx - 1] == bomb[bomb_len - 1]) {
			int cnt = 1;
			for (int j = 1; j < bomb_len; j++) {
				if (result[idx - j - 1] != bomb[bomb_len - j - 1]) {
					break;
				}
				cnt++;
			}
			if (cnt == bomb_len) {
				for (int k = 0; k < bomb_len; k++)
					result.pop_back();
				idx -= bomb_len;
			}
		}
	}
	if (result.length() != 0)
		printf("%s\n", result.c_str());
	else
		printf("FRULA\n");
	return 0;
}