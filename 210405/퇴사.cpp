#include <bits/stdc++.h>
 
using namespace std;

int N, time_arr[16], profit_arr[16], max_val;;
 
void solve(int now_day, int now_sum, int added_num){
    if(now_day == N + 1 ){
        max_val = max(max_val, now_sum);
        return ;
    } 
    else if (now_day > N + 1){
        max_val = max(max_val, now_sum-added_num);
        return ;
    }
 
    for ( int i = now_day + time_arr[now_day] ; i <= N + time_arr[now_day] ; i++)
        solve(i, now_sum + profit_arr[now_day] , profit_arr[now_day]);   
}
 
int main(){
    cin >> N;
    
    for ( int i = 1 ; i <= N; i++){
        cin >> time_arr[i]  >> profit_arr[i] ;
    }
    
    for ( int i = 1 ; i <= N ; i++){
        solve(i, 0, 0);
    }
    cout << max_val;
}
 
