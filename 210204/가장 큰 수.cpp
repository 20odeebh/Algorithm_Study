#include <bits/stdc++.h>

using namespace std;
bool cmp(string a,string b){
        return a+b>b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> n;
    
    for(int a:numbers) {
        n.push_back(to_string(a));
    }  
    sort(n.begin(),n.end(),cmp);
    for(auto a:n) answer+=a;
    if(answer[0]=='0') return "0";
    return answer;
}