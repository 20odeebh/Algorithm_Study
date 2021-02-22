#include <bits/stdc++.h>

using namespace std;

bool v[200];
void go(int cur,int n,vector<vector<int>> computers, int cnt){
    v[cur] = true;
    for(int next = 0;next<n;next++){
        if(computers[cur][next] )go(next,n,computers,cnt);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(v[i]) continue;
        go(i,n,computers,++answer);
    }
    return answer;
}