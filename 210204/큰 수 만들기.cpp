#include <bits/stdc++.h>

using namespace std;
 
string solution(string number, int k) {
    string answer = ""; 
    int size = number.size() - k;
    int start = 0;
    
    for(int i=0; i<size; i++) {
        int mx = start;
        for(int j=start; j<=k+i; j++) {
            if(number[start] < number[j]) {
                number[start] = number[j];
                mx = j;
            }
        }
        answer += number[start];
        start = mx + 1;        
    }
 
    return answer;
}
