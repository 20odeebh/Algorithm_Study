#include <string>
#include <vector>
#include <iostream>

using namespace std;
// DP + 규칙 (★)

// 특징 1. 인접한 숫자끼리 삭제해나가는 규칙 
// 특징 2. 항상 큰 수 삭제, 작은 수는 한 번만 삭제 가능
// => 나를 기준으로 나보다 왼쪽에 있는 수들은 항상 큰 수가 없어지는 규칙 (따라서 최솟값)
// => 나를 기준으로 나보다 오른쪽에 있는 수들은 항상 큰 수가 없어지는 규칙 (최솟값)
// => 최종적으로 세 수 (왼쪽 최솟값) (나) (오른쪽 최솟값)이 남았을 때 
// => 두 수 모두 나보다 큰 수이면 남을 수 없다 (작은 값 삭제를 두번 할 수 없기 때문)
#define MAX 1000000

int left_arr[MAX];
int right_arr[MAX];

int solution(vector<int> a) {
    int answer = 0;
    
    // left[i] : i인덱스 이전의 모든 값 중 최솟값
    left_arr[0]=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]<left_arr[i-1])
            left_arr[i]=a[i];
        else
            left_arr[i]=left_arr[i-1];
    }
    // right[i] : i인덱스 이후의 모든 값 중 최솟값 
    right_arr[a.size()-1]=a[a.size()-1];
    for(int i=a.size()-2;i>=0;i--){
        if(a[i]<right_arr[i+1])
            right_arr[i]=a[i];
        else
            right_arr[i]=right_arr[i+1];
    }
    
    for(int i=0;i<a.size();i++){
        if(a[i]>right_arr[i] && a[i]>left_arr[i])
            continue;
        answer++;
    }
    
    
    return answer;
}