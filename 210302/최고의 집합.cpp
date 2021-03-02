#include <string>
#include <vector>
#include <iostream>

using namespace std;

// n개로 이루어진 중복 집합
// s을 n개의 수로 나누기 
// brute force 불가능
// 특징 : 최대한 균일하게 모아야 곱이 가장 커진다.

vector<int> solution(int n, int s) {
    vector<int> answer;
    // s를 n개로 쪼갤 수 없음
    if(s<n){
        answer.push_back(-1);
        return answer;
    }

    // 수를 적절히 분배하기 
    for(int i=0;i<n;i++){
        answer.push_back(s/n);
    }
    // 균등하게 나눈 후 나머지를 차례로 나누어 준다. 
    // 나머지는 항상 s/n보다 작은 값이기 때문에 가능
    int last = s-s/n*n;
    int idx = answer.size()-1;
    while(last!=0){
        answer[idx]+=1;
        last--;
        idx--;
    }
    
    return answer;
}