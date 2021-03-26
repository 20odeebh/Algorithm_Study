#include <bits/stdc++.h>

using namespace std;

 int overlapCnt, visited[1000];
vector<string> s1,s2;

int solution(string str1, string str2) 
{
 
    for(int i = 0; i <= str1.size()-2; i++)
    {
        if((('A' <= str1[i] && str1[i] <= 'Z') || ('a' <= str1[i] && str1[i] <= 'z')) && (('A' <= str1[i+1] && str1[i+1] <= 'Z') || ('a' <= str1[i+1] && str1[i+1] <= 'z')))
        {
            string temp;
            temp += tolower(str1[i]);
            temp += tolower(str1[i+1]);
            
            s1.push_back(temp);
        }
    }
    
    for(int i = 0; i <= str2.size()-2; i++)
    {   
        if((('A' <= str2[i] && str2[i] <= 'Z') || ('a' <= str2[i] && str2[i] <= 'z')) && (('A' <= str2[i+1] && str2[i+1] <= 'Z') || ('a' <= str2[i+1] && str2[i+1] <= 'z')))
        {
            string temp;
            temp += tolower(str2[i]);
            temp += tolower(str2[i+1]);
            
            s2.push_back(temp);
        }
    }
    
    for(int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            if(s1[i] == s2[j] && visited[j] == 0)
            {
                visited[j] = 1;
                overlapCnt++;
                break;
            }
        }
    }
    
    if(overlapCnt == 0)
    {
        if(s1.size() + s2.size() - overlapCnt == 0)
        {
            return 65536;       
        }
        else
        {
            return 0;
        }
    }
    else
    {
        double zacard = overlapCnt / (double)(s1.size() + s2.size() - overlapCnt);
 
        return zacard * 65536;
    }
}
