#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end());
    
    int s = routes[0][0];
    int e = routes[0][1];
    
    for(int i=1;i<routes.size();i++){
        s = routes[i][0];
        if(routes[i][0]>e){
            answer++;           
            e = routes[i][1];
        }
        else{
            e = min(e,routes[i][1]);
        }       
    }
    return answer;
}