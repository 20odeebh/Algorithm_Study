#include <string>

using namespace std;

bool DP[2510][2510];

int Max(int A, int B) { if (A > B) return A; return B; }

int solution(string s)
{
	int answer = 1;
	for (int i = 0; i < s.length(); i++) DP[i][i] = true;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			DP[i][i + 1] = true;
			answer = 2;
		}
	}

	for (int Len = 3; Len <= s.length(); Len++)
	{
		for (int Start = 0; Start <= s.length() - Len; Start++)
		{
			int End = Start + Len - 1;

			if (s[Start] == s[End] && DP[Start + 1][End - 1] == true)
			{
				DP[Start][End] = true;
				answer = Max(answer, Len);
			}
		}
	}

	return answer;
}