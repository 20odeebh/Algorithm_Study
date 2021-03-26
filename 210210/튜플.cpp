#include <bits/stdc++.h>

using namespace std;


int check[100001];

bool cmp(vector<int> a, vector<int> b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    vector<int> answer;   
    vector<int> v;     
    vector<vector<int>> rs;
    string t="";
    
    for(int i=1;i<s.size()-1;i++){
        
        if(s[i] == '{') {
            v.clear();
        }
        
        else if(s[i] == ',') {
            
            if(s[i+1] == '{') continue;
            else {
                v.push_back(stoi(t));
                t="";
            }
            
        }
        else if(s[i] == '}') {
            v.push_back(stoi(t));
            t="";
            rs.push_back(v);
        }
        else t+=s[i];
    }
    
    sort(rs.begin(),rs.end(),cmp);
    
    for(int i=0;i<rs.size();i++){
        for(int j=0;j<rs[i].size();j++){
            
            if(check[rs[i][j]] == 0){
                check[rs[i][j]] = 1;
                answer.push_back(rs[i][j]);
            }
            
        }
    }
       
    return answer;
}
