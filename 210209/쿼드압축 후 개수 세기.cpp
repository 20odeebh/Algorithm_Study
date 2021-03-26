#include <bits/stdc++.h>

using namespace std;
int cnt_1,cnt_0;

int a[1024][1024];

void go(int y,int x, int n){
    //cout<<y<<" "<<x<<" "<<n<<"\n";
    int c0=0,c1=0;
    if(n == 1){
        a[y][x] == 1 ? cnt_1++ : cnt_0++;
        return;
    }
    for(int i=y;i<y+n;i++){
       for(int j=x;j<x+n;j++){
           
           a[i][j] == 1 ? c1++ : c0++;
       }
    }
    if(c1 != 0&& c0 != 0){
        go(y,x,n/2);
        go(y,x+n/2,n/2);
        go(y+n/2,x,n/2);
        go(y+n/2,x+n/2,n/2);
    }
    else if (c1>0){
        cnt_1++;
    }
    else{
        cnt_0++;
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
       for(int j=0;j<arr[i].size();j++){
           a[i][j]=arr[i][j];
       }
    }
    go(0,0,arr.size());
    answer.push_back(cnt_0);
    answer.push_back(cnt_1);
    //cout<<cnt_1<<" "<<cnt_0;
    return answer;
}