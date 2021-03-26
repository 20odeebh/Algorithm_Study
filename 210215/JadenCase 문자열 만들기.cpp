#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	int index = 0;
	
	bool prev_blank = true;
	
	while (index < s.size())
	{
		if (prev_blank && s[index] != ' ')
		{
			s[index] = toupper(s[index]);
			prev_blank = false; 
		}
		else if (s[index] == ' ')
		{
			prev_blank = true;
		}
		else if(isupper(s[index]))
		{
			s[index] = tolower(s[index]);
		}

		answer += s[index];
		index += 1;
	}

	return answer;
}
