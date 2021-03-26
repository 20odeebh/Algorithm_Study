#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    int j=6;
    stack<string> stk;
    vector<int> v={};
    for(int j=1;j<s.size();j++){
        for(int i=0;i<s.size();i+=j){
            stk.push(s.substr(i,j));
        }
    string comp=stk.top();
    string ans="";
    stk.pop();
    int cnt = 1;
    
    while(!stk.empty()){
        if(comp == stk.top()){
            cnt++;
            stk.pop();
        }
        else{
            if(cnt!=1) ans=to_string(cnt)+comp+ans;
            else ans=comp+ans;            
            comp = stk.top();
            stk.pop();
            cnt=1;
        }
        if(stk.empty()) {
            if(cnt!=1) ans=to_string(cnt)+comp+ans;
            else ans=comp+ans; 
        }
    }
        //cout<<ans.size()<<" ";
    v.push_back(ans.size());
    ans="";
    }
    v.push_back(s.size());
    
    return *min_element(v.begin(),v.end());
}