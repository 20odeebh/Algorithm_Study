#include <bits/stdc++.h>

using namespace std;

vector <string> uid;
vector <string> bid;

int usize; int bsize;
int visited[8]={0,};

set <vector <string> > s;

vector <int> v;
int answer=0;

bool isSame(string a, string b)
{
    if(a.size()!=b.size())
        return false;
    bool isFalse=0;
    for(int i=0;i<a.size();i++)
    {
        if(b[i]=='*') continue;
        if(a[i]!=b[i])
        {
            isFalse=1;
            break;
        }
    }
    if(isFalse==1) return false;
    return true;
}

void dfs() {

    if(v.size()==bsize)
    {
        bool isAnswer=1;
        
        for(int i=0;i<v.size();i++)
            if(!isSame(uid[v[i]],bid[i]))
            {
             isAnswer=0;
                break;
            }
        
        if(isAnswer==1)
        {
            vector <string> temp;
            
            for(int i=0;i<v.size();i++)
                temp.push_back(uid[v[i]]);
            
            sort(temp.begin(),temp.end());
            
            if(s.find(temp)==s.end())
            {
                answer++;
                s.insert(temp);
            }
        }
        return;
    }
    
    for(int i=0;i<usize;i++)
    {
        if(visited[i]!=0) continue;
        
		visited[i]=1;
        v.push_back(i);
        dfs();
        v.pop_back();
        visited[i]=0;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    uid=user_id; bid=banned_id;
    usize=uid.size(); bsize=bid.size();
    dfs();
    return answer;
}