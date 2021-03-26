#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int mx=-987654321,mn=987654321,num=0;
    string t="";
    for(int i=0;i<s.size();i++){
        
       if(s[i] == ' '){
           num = stoi(t);
           mx=max(num,mx);
           mn=min(num,mn);
           t="";
       }
        else t+=s[i];
    }
    
    num = stoi(t);
    mx=max(num,mx);
    mn=min(num,mn);
   
    return to_string(mn)+" "+to_string(mx);
}