#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
	stack<char> a;

	for (char i : s)
		if (a.empty() || a.top() != i)	a.push(i);
		else	a.pop();
    return a.empty();
}