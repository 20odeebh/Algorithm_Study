#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(string s)
{
	string answer = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			answer += s[i];
			continue;
		}
		else
		{
			// ���� ���� ù���� or �� ù����
			if (s[i - 1] == ' ' || i == 0)
			{
				// ù���ڰ� �ҹ����� ��� -> �빮��
				if ('a' <= s[i] && s[i] <= 'z')
				{
					s[i] = s[i] - 'a' + 'A';
				}
			}
			// �̾����� ���ڰ� �빮���� ��� -> �ҹ���
			else
			{
				if ('A' <= s[i] && s[i] <= 'Z')
				{
					s[i] = s[i] - 'A' + 'a';
				}
			}
		}
		answer += s[i];
	}
	return s;
}