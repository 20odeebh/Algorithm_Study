#include <bits/stdc++.h>

using namespace std;

vector<int> answer;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string,int> genreAndPlay;
    map<int,string> reverseMap;
    
	int tmp=0;
    string genre;
    vector<pair<int,int>> order;
    
	for(int a = 0;a<genres.size(); a++)
    {
        genreAndPlay[genres[a]]=0;
    }
    
	for(int a = 0;a<plays.size(); a++)
    {
        tmp = genreAndPlay[genres[a]]+plays[a];
        genreAndPlay[genres[a]]=tmp;
    }

    for(auto a = genreAndPlay.begin(); a!=genreAndPlay.end(); a++)
    {
        reverseMap.insert({a->second,a->first});
    }
    
    for(auto a = reverseMap.rbegin(); a!=reverseMap.rend(); ++a)
    {
        for(int i=0 ; i<genres.size(); i++)
        {
            if(genres[i]==a->second)
            {
                order.push_back({i,plays[i]});
            }
        }
        sort(order.begin(),order.end(),cmp);
        auto odrIt = order.begin();
        answer.push_back(odrIt->first);
        odrIt++;
        if(odrIt!=order.end())
        {
            answer.push_back(odrIt->first);
        }
        order.clear();
    } 

    return answer;
}