#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int len = s.size();
    
    while(len >= 2){
        for(int i=0;i<= s.size()-len;i++){
            int start=i;
            int end=len+i-1;
            bool flag = true;
            while(start<end){
                if(s[start] != s[end]){
                    flag = false;
                    break;
                }
                start++;
                end--;
            }
            if(flag) return len;
        }
        len--;
    }
    return 1;
}