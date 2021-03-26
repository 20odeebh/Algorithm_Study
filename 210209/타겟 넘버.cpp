#include <bits/stdc++.h>

using namespace std;

int cnt=0;
void dfs(int rt, int sum,vector<int> numbers, int target){
   //cout<<rt<<" "<<sum<<"\n";
    if(rt ==numbers.size()-1 ){
        if(sum == target){
            cnt++;
        } 
        return;
    }
    
    dfs(rt+1,sum+numbers[rt+1],numbers,target);
    dfs(rt+1,sum-numbers[rt+1],numbers,target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
   
   
    dfs(-1,0,numbers,target);
    return cnt;
}