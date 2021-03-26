#include <bits/stdc++.h>
 
using namespace std;
 
string arr[100000][3];
 
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    char buff[30];
    map<string, string> m;
    
    int index = 0;
    for(auto r : record) {
        
        strcpy(buff, r.c_str());
        int cnt = 0;       
       
        char *tok = strtok(buff, " ");
        while (tok != nullptr) {
          
            arr[index][cnt++] = string(tok);            
            tok = strtok(nullptr, " ");
        }
               
      
        if(arr[index][0] == "Enter" || arr[index][0] == "Change") {
            if(m.find(arr[index][1]) == m.end()) {
                m.insert(make_pair(arr[index][1],arr[index][2]));
            } else {
                m[arr[index][1]] = arr[index][2];
            }
        }
        
        index++;
    }
       
    int size = record.size();
    for(int i=0; i<size; i++) {
        if(arr[i][0] == "Enter") {
            answer.push_back(m[arr[i][1]] + "님이 들어왔습니다.");
        } else if(arr[i][0] == "Leave") {
            answer.push_back(m[arr[i][1]] + "님이 나갔습니다.");
        }
    }
    
    
    return answer;
}