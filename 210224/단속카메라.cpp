#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 그리디 : 최대한 겹칠 수 있게 카메라를 설치해야함

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end());
    int end_time = routes[0][1];
    for(int i=1;i<routes.size();i++){
        int cur_start = routes[i][0];
        int cur_end = routes[i][1];
        // 현재 카메라를 설치할 수 있는 범위인 end_time보다 시작 시간이 더 길면 겹쳐서 설치할 수 없음 
        if(end_time<cur_start){
            end_time = cur_end;
            answer++;
        }
        // 그렇지 않으면 갱신 가능, 단 cur_end가 end_time보다 작으면 겹쳐서 설치할 수 있는 범위가 줄기 때문에 갱신해야함
        else{
            if(end_time>cur_end)
                end_time = cur_end;
        }
    }
    
    return answer;
}