#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater());
    while(answer<citations.size()){
        if (answer<citations[answer]) answer++;
        else break;
    }
    return answer;
}