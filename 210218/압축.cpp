#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> d;
    int num = 1;
    
	for(; num<27; num++){
        char put = 'A' + (num-1);
        string s;
        
		s.push_back(put);
        d[s] = num;
    }
    while(msg.size()!= 0){
        for(int i=1;i<=msg.size();i++){
            string sub = msg.substr(0, i);
            if(d[sub] == 0){ 
                d[sub] = num++;
                
				string p = msg.substr(0, i-1);
                answer.push_back(d[p]);
                
				msg = msg.substr(i-1, msg.size()-p.size());
                break;
            }else{
                
				if(msg.size() == i){
                    answer.push_back(d[msg]);
                    msg = "";
                }
            }
        }
    }  
    return answer;
}