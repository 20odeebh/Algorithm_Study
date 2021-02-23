#include <bits/stdc++.h>
using namespace std;
int d[501][501];
//d[i][j] = i행 j 열에서 가질 수 있는 숫자 합의 최대값
//d[i][j] = max(d[i-1][j],d[i-1][j-1])+a[i][j]
//구현은 위층에서 아래층으로 최대값을 주는 방식
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            d[i][j] = triangle[i][j];
        }
    }
    int size2 = size - 1;
    for (int i = 0; i < size2; i++) {
        for (int j = 0; j <= i; j++) {
            d[i + 1][j] = max(d[i + 1][j], d[i][j] + triangle[i + 1][j]);
            d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + triangle[i + 1][j + 1]);
        }
    }
    for (int i = 0; i < size; i++) {
        answer = max(answer, d[size2][i]);
    }
    return answer;
}