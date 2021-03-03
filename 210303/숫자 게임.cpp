#include <bits/stdc++.h>

using namespace std;
// 그리디 : A 고정되어 있어도, 어차피 B의 정렬에 따라서 A의 정렬이 달라지기 때문에 A도 정렬해도 된다.
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    // 각각 erase했을 때 시간초과가 발생하면 인덱싱 처리로 진행한다.
    int j=0;
    for(int i=0;i<B.size();i++){
        int cur = B[i];
        if(cur>A[j]){
            j++;
            answer++;
        }
    }
    return answer;
}