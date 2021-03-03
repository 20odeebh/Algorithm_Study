#include <iostream>
#include <vector>
using namespace std;
// 그리디하게 진행
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int idx=1;
    int i=0;
    while(idx<=n){
        // stations에는 오름차순으로 정렬되어있다는 특징을 사용해서
        // 해당 범위 안에 있으면 stations 사용, i와 idx를 적절하게 변경
        if(idx>=stations[i]-w && idx <= stations[i]+w){
            idx = stations[i]+w+1;
            i++;
        }
        // 그렇지 않으면 가장 많은 곳에 영향을 줄 수 있는 중간 위치에 설치 후 idx 변경
        else{
            idx+=2*w+1;
            answer++;
        }
    }

    return answer;
}