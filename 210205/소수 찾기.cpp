#include <bits/stdc++.h>

using namespace std;



bool Included(int num, string str)
{
    string strNum = to_string(num); 
    for(int i=0; i<strNum.size(); i++) {
        int flag = false;
        for(int j=0; j<str.size(); j++) {
            if(strNum.at(i) == str.at(j)) {
                flag = true;
                str.at(j) = ' '; 
                break;
            }
        }
        if(!flag) 
            return false;
    }
    return true;
}

bool Prime(int num)
{
    if(num<2) return false;
    for(int i=2; i<=sqrt(num); i++) 
        if(num%i==0) return false;
    return true;
}
int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end(), greater<int>()); 
    int mx = stoi(numbers); 
    
    for(int i=0; i<=mx; i++) {
        if(Prime(i) && Included(i, numbers)) { 
            answer++;
        }
    }
    return answer;
}