#include <bits/stdc++.h>

using namespace std;
deque<int> d;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i=0;i<operations.size();i++){
        char oper = operations[i][0];
        int digit = stoi(operations[i].substr(2));
        if(oper == 'I'){
            d.push_back(digit);
            sort(d.begin(),d.end());
        }
        else{
            if(d.size() == 0) continue;
            if(digit == 1) d.pop_back();
            else d.pop_front();
        }                         
    }
                   
    if(d.size() != 0) {
        answer.push_back(d.back());
        answer.push_back(d.front());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}