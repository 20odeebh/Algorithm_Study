#include <bits/stdc++.h>

using namespace std;
// 가짓수 너무 많음 -> 이분탐색

bool canGo(int peoples, vector<int> &v, int k){
    int cnt=0;
    for(auto &a:v){
        // 그림을 자세히 이해하기, peoples를 빼는것이 아니라 그 전 번째 친구가 징검다리를 건넌 후 값을 살펴봐야한다.
        if(a-peoples+1<=0){
            cnt++;
        }
        else{
            cnt=0;
        }
        if(cnt>=k)
            return false;
    }
    return true;
    
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left=200000000;
    int right=0;
    
    for(auto &k:stones){
        left=1;
        right=max(right,k);
    }
    
    while(left<=right){
        int mid = (left+right)/2;
        // mid 명 수 통과할 수 있으면
        if(canGo(mid,stones,k)){
            left=mid+1;
            answer = mid;
        }
        else{
            right=mid-1;
        }
    }
    
    return answer;
}