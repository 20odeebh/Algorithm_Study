#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> v(n+1,0);
    v[1]=1, v[2]=2; 
    for(int i=3;i<=n;i++){
        v[i] = (v[i-1] + v[i-2]) % 1000000007;
    }
    answer = v[n];
    return answer;
}