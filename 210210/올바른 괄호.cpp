#include<bits/stdc++.h>

using namespace std;

stack<char> stk;
bool solution(string s)
{
    bool answer = true;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') stk.push(s[i]);
        else {
            if(stk.empty() || stk.top() == ')') return false;
            else stk.pop();
        }
    }
    return stk.empty();
}