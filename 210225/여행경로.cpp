#include <bits/stdc++.h>

using namespace std;

int n;
bool dfs(vector<vector<string>> const tickets, vector<string> &route, vector<bool> &visited, string dst){
    route.push_back(dst);
    
	if(route.size() == n+1) return true;
    
	for(int i = 0; i<n; i++){
        if(!visited[i] && tickets[i][0] == dst){
            visited[i] = true;
            if(dfs(tickets, route, visited, tickets[i][1])){
                return true;
            }
            visited[i] = false;
        }
    }
    
	route.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();
    sort(tickets.begin(), tickets.end());
    
	for(int i = 0; i < n; i++){
        vector<bool> visited(n, false);
        vector<string> route;
        
		if(tickets[i][0] == "ICN"){
            visited[i] = true;
            route.push_back("ICN");
            if(dfs(tickets, route, visited, tickets[i][1])){
                answer = route;
                break;
            }
           
        }
    }
    return answer;
}