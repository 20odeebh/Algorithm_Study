#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arr[101][101]={0,};
    
    for(int i=0; i<results.size(); i++){
        arr[results[i][0]][results[i][1]] = 1;
    }
    
    for(int c=1; c<=n; c++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
			
                if(arr[i][c]==1&&arr[c][j]==1){ arr[i][j]=1; }
            }
        }
    }
    
    for(int c=1; c<=n; c++){
        int check=0;
		
        for(int i=1; i<=n; i++){
            check += (arr[i][c]+arr[c][i]);
        }
        if(check==n-1){ answer++; }
    }
    return answer;
    
}