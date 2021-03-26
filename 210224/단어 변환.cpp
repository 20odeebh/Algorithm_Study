#include <bits/stdc++.h>

using namespace std;
int  v[51], MIN=987654321;

bool check(string a,string b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) cnt++;
    }
    
    return cnt == 1;
}
void go(int rt, string begin, string target, vector<string> words){
     if(begin == target){
         MIN=min(MIN,rt);
         return;
     }
    for(int i=0;i<words.size();i++){
        if(check(begin,words[i])){ 
            if(v[i] == 0){
                v[i] = 1;
                go(rt+1,words[i],target,words);
                v[i] = 0;
            }            
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    go(0,begin,target,words);
    if(MIN == 987654321) MIN=0;
    return MIN;
}