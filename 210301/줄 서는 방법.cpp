#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
vector<int> solution(int n, long long k) {
    vector<int> answer;          
    ll fact = 1;
    vector<int> row;
    
    for (int i = 1; i <=n; i++) {
        fact *= i;
        row.push_back(i);
    }
    
    int res[n];
    memset(res, 0, sizeof(res));
    int idx= 0;
    
    while(n>0) {
        fact /= n--;
        
        int tmp_idx =(int) (k / fact); 
        int tmp_remain = (int) (k% fact);
        
        if (tmp_remain == 0) {
            tmp_idx--;
            res[idx++] = row.at(tmp_idx);
            row.erase(row.begin() + tmp_idx); 
            break; 
        } 
        res[idx++] = row.at(tmp_idx);
        row.erase(row.begin() + tmp_idx);
        
        k %= fact;       
    }