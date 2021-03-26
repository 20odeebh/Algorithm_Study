#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;   
    vector < vector <int> > s;    
    string str;
  
    int mfi,mst;
    for(int i=0; i<lines.size(); i++)
    {
		mfi=0;
        mst=0;
		       
        mfi+=stoi(lines[i].substr(11,2))*3600000; 
        mfi+=stoi(lines[i].substr(14,2))*60000;   
        mfi+=stoi(lines[i].substr(17,2))*1000;
        mfi+=stoi(lines[i].substr(20,3));
        
        mst=mfi-(int)((stod(lines[i].substr(24)))*1000-1); 
        mfi++;
        
        vector<int> t1,t2,t3;
        t1.push_back(mst);
        t1.push_back(0);
        
        t2.push_back(mfi);
        t2.push_back(1);
               
        s.push_back(t1);
        s.push_back(t2);
        
    }
    
    sort(s.begin(),s.end());
  
    int myst=-100000;
    int cnt=0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(myst==s[i][0]){           
            s[i][1]==0? cnt++ : cnt--;
        }
        else{
            int ccnt=0;
            int sc=s[i][0];
            if(s[i][1]==1) sc--;
            for(int j=i; j<s.size(); j++){           {
                if(s[j][0]-sc>=1000) break;                   
                if(s[j][1]==0) ccnt++;
            }
            
            if(cnt+ccnt>answer) answer=cnt+ccnt;           
         
            myst=s[i][0];
            s[i][1]==0 ? cnt++ : cnt--;
        }     
    }   
    return answer;
}
