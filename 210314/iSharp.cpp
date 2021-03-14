#include <iostream>
#include <string>
#include <deque>
#include <sstream>
using namespace std;
bool IsAlpha(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= 'A' && ch <= 'Z')
		return true;
	return false;
}
int main()
{
	string syntax;
	getline(cin, syntax);
	istringstream ss(syntax);
	string data, type;
	getline(ss, data, ' ');
	type = data;
	deque<char> dq;
	while (getline(ss, data, ' ')) {
		dq.push_back(' ');
		for (const auto& ch : data) {
			if (ch == ',')
				break;
			if (IsAlpha(ch))
				dq.push_back(ch);
			else if (ch == '*' || ch == '&' || ch == ']') {
				dq.push_front(ch);
				if (ch == ']')
					dq.push_front('[');
			}
		}
		dq.push_back(';');
		printf("%s", type.c_str());
		for (const auto& ch : dq)
			printf("%c", ch);
		printf("\n");
		dq.clear();
	}
	return 0;
}