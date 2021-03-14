#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> var;
vector<string> back;
string comm;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char ch;

	cin >> comm;
	string temp = "";
	while(1)
	{
		cin >> ch;
		
		if (ch == ';')
		{
			var.push_back(temp);
			temp = "";
			break;
		}
		if (ch == ',')
		{
			var.push_back(temp);
			temp = "";
			continue;
		}
		if (ch == ' ') continue;
		temp += ch;
	}

	int var_size = var.size();

	for (int i = 0; i < var_size; ++i)
	{
		string cur = var[i];
		string temp = "";
		string t_var = "";
		int cur_len = cur.length();

		for (int k = 0; k < cur_len; ++k)
		{
			char ch = var[i][k];
			if (ch == '*' || ch == '[' || ch == ']' || ch == '&') temp += ch;
			else t_var += ch;
		}
		var[i] = t_var;
		reverse(temp.begin(), temp.end());
		int temp_len = temp.length();
		char tp;
		string temp2 = "";
		for (int i = 0; i < temp_len; ++i)
		{
			tp = temp[i];
			if (tp == ']' || tp == '[')
			{
				temp2 += "[]";
				++i;
				continue;
			}
			temp2 += tp;
		}
		back.push_back(temp2);
	}

	for (int i = 0; i < var_size; ++i)
	{
		cout << comm << back[i] << ' ' << var[i] << ';' << '\n';
	}
	
	return 0;
}