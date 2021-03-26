#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}

int solution(vector<int> a) {
    if(a.size() < 2) return 0;    
    int answer = 0;
    int len = a.size();
    vector<pair<int,int> > check(len+1,{0,0});
    for(int i = 0 ; i <= len ; i++) 
        check[i].first = i;    
    for(int i = 0 ; i < len ; i++) {
        int n = a[i];        
        check[n].second++;    
    }    
    sort(check.begin(), check.end(), cmp);
    for(auto& pr : check) {
        int candidate = pr.first;
        if(pr.second*2 <= answer) continue;
        int ans = 0;        
        bool can_f = false, num_f = false;
        for(auto& num : a) {
            if(num == candidate) {
                if(can_f) continue;
                can_f = true;
                if(can_f && num_f) {
                    can_f = false;
                    num_f = false;
                    ans += 2;
                }
            }else {
                if(num_f) continue;                
                num_f = true;
                if(can_f && num_f) {
                    can_f = false;
                    num_f = false;
                    ans += 2;
                }
            }
        }
        if(ans > answer) {
            answer = ans;            
        }
    }    
    return answer;
}