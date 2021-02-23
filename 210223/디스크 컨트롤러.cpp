#include <string>
#include <vector>
#include <queue>

using namespace std;
// 요청부터 종료 시간 최소 
// 현재 시간 안에 들어온 값(시작) 들 중에서 가장 짧은 작업부터 진행하기 

// 1. 수행 안하면 먼저 요청이 들어온 작업부터 진행 => 먼저 들어온 순서대로 정렬하는 배열 만들기
// 2. 수행 중에 새로운 것들이 들어오면 짧은것부터 처리하기 위해 pq에 따로 저장 (가장 진행시간이 짧은 것부터 진행)
// 3. pq에서 하나 빼서 진행할 때도 time은 증가한다. 이 때 다시 time안에 시작하는 작업에 대해서 pq에 넣어주어야한다. 


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>job;
    // job에 들어온 순서대로 넣기
    for(auto &k:jobs)
        job.push({k[0],k[1]});
    
    int time=0;
    
    while(!job.empty()){
        // 작업 수행하고 있지 않을 때 하나 뽑기
        int start_time = job.top().first;
        int last_time = job.top().second;
        // 들어오자마자 진행됐으니까 기다린 시간 없음
        answer+=last_time;
        // 시간은 시작 시간에다 진행시간 더한 것 
        time = start_time+last_time;
        job.pop();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // 해당 작업을 진행하고 있을 때 들어온 작업들 짧게 걸리는 순서대로 pq에 저장
        while(!job.empty()){
            if(job.top().first<=time){
                pq.push({job.top().second,job.top().first});
                job.pop();
            }
            else
                break;
        }
        // 각각에 대해서 얼마나 걸렸는지 확인
        while(!pq.empty()){
            int start_time = pq.top().second;
            int last_time = pq.top().first;
            // 기다린 시간을 더해줘야한다
            answer += time-start_time+last_time;
            time += last_time;
            pq.pop();
            // pq에 저장된 값을 처리해서 time이 변화했을 때도 time안에 들어온 값을 넣어주어한다.
            while(!job.empty()){
                if(job.top().first<=time){
                    pq.push({job.top().second,job.top().first});
                    job.pop();
                }
                else
                    break;
            }
        }
    }

    answer /= jobs.size();
    
    return answer;
}