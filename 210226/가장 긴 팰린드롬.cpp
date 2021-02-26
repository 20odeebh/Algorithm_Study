#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// 50분

int solution(string s)
{
    int answer =1;
    // 문자열의 길이를 기준으로 펠린드롬 검사하기
    int len = s.size();
    while(len>=2){
        for(int i=0;i<s.size();i++){
            int left = i;
            int right = i+len-1;
            if(right>s.size()-1)
                continue;
            bool flag=true;
            // 이렇게 진행하면 개수가 짝수이든, 홀수이든 상관 없다.
            while(left<=right){
                if(s[left++]!=s[right--]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return len;
            }
        }
        len--;
    }
    return answer;
    
}