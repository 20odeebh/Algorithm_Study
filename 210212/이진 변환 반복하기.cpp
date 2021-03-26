#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt=0;
    int rt=0;
    
    while(s != "1"){
        string t = "";
        int x=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '0') x++;
            else t+=s[i];
        }
    
        int n = s.size()-x;
        t="";
        while(n){
           t=to_string(n%2)+t;
            n/=2;
        }
        s=t;
        cnt+=x;        
        rt++;
    }
    answer.push_back(rt);
    answer.push_back(cnt);
        
    return answer;
}