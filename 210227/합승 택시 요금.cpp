#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 최단거리(다익스트라 알고리즘) + 경로 구해서 중복된 값 빼주기
// 다익스트라로 진행할 경우에는 모든 점에 대해서 각각 계산한 후 진행하기 !
// 플로이드 와샬

int weight_val[202][202];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            weight_val[i][j]=10000000;
    }
    
    for(auto &k:fares){
        int n1 = k[0];
        int n2 = k[1];
        int w = k[2];
        weight_val[n1][n2]=w;
        weight_val[n2][n1]=w;
    }
    
    for(int i=1;i<=n;i++){
        weight_val[i][i]=0;
    }
    
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				weight_val[i][j]=min(weight_val[i][j],weight_val[i][k]+weight_val[k][j]);

    // 합승하지 않는 경우
    answer = weight_val[s][a]+weight_val[s][b];
    
    // 합승하는 경우
    for(int i=1;i<=n;i++){
        int d1 = weight_val[s][i]+weight_val[i][a];
        int d2 = weight_val[i][b];
        answer = min(d1+d2,answer);
    }
    
    return answer;
}