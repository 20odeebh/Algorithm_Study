#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> num;
long long fac[21];
// 직접 구하면 시간 복잡도가 너무 크다. 효율성 통과 x
// 순열의 특징 사용
// 1__ (2!개 존재)
// 2__ (2!개 존재)
// 따라서 k가 5일 때 첫번째 자리수는 3임을 알 수 있다. 

void calFact(int n){
    fac[0]=0;
    fac[1]=1;
    for(int i=2;i<=n;i++){
        fac[i]=i*fac[i-1];
    }
    return;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    for(int i=1;i<=n;i++)
        num.push_back(i);
    calFact(n);
    
    // 현재 자리수 값을 factorial 값을 사용해서 찾는다.
    for(int i=n-1;i>0;i--){
        int cnt=0;
        while(k-fac[i]>0){
            k-=fac[i];
            cnt++;
        }
        answer.push_back(num[cnt]);
        num.erase(num.begin()+cnt);
    }
    // 마지막은 남은 값 하나 
    answer.push_back(num[0]);
    
    return answer;
}