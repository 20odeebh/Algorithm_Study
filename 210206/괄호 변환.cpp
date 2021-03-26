#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    stack<char> stk;
    
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            if(stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }
        else stk.push(s[i]);
    }
    
    return stk.empty();
}

string go (string s){
    if(s.size() == 0) return "";
    
    int open=0,close=0;
    string u="",v="";
    
    for(int i=0;i<s.size();i++){
        s[i] == '('? open++:close++;
        
        if(open == close){
            u=s.substr(0,i+1);
            v=s.substr(i+1,s.size()-i);
            //cout<<u<<" "<<v;
            break;            
        }                
    }
    
    if(check(u)) return u+go(v);
    else {
        string temp="";
        temp="("+go(v)+")";
        u.erase(u.begin());
        u.erase(u.end()-1);
        for(int i=0;i<u.size();i++){
            u[i] = (u[i] == '(')? ')': '(';
        }
        temp+=u;
        return temp;       
    }           
}

string solution(string p) {
    return go(p);
}