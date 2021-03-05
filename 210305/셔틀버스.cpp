#include <bits/stdc++.h>

using namespace std;
// 36분

string changed(int hour, int minute){
    string sh,sm;
    if(hour<10){
        sh = '0';
        sh += hour+'0';
    }
    else
        sh = to_string(hour);
    if(minute<10){
        sm = '0';
        sm += minute+'0';
    }
    else
        sm = to_string(minute);
    return sh+':'+sm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    // 분으로 환산하기 
    int start = 60*9;
    // 마지막 셔틀의 출발 시간, 콘은 이 때 버스를 타야 한다.
    int last_shuttle = (n-1)*t+start;
    sort(timetable.begin(),timetable.end());
    vector<int> together;
    // 정렬한 후, (n-2)*t+start와 같거나 작은 아이들 중 m*(n-1)명 제외
    
    int idx=0;
    int cnt = m*(n-1);
    while(!timetable.empty()){
        if(cnt==0)
            break;
        string k = timetable.front();
        int hour = stoi(k.substr(0,2));
        int minute = stoi(k.substr(3,2));
        int total = hour*60+minute;
        // 현재 시작 시점 이전에 출발한 크루들 최대 cnt명까지 삭제
        if(total<=last_shuttle-t){
            timetable.erase(timetable.begin());
            cnt--;
        }
        else
            break;
    }

    for(int i=0;i<timetable.size();i++){
        string k = timetable[i];
        int hour = stoi(k.substr(0,2));
        int minute = stoi(k.substr(3,2));
        int total = hour*60+minute;
        if(total<=last_shuttle){
            together.push_back(total);            
        }
        if(together.size()==m)
            break;
    }
    
    int hour;
    int minute;
    // 같이 탈 크루가 없으면 제일 늦은 시작에 도착하면 된다...
    if(together.empty()){
        hour = last_shuttle/60;
        minute = last_shuttle%60;
    }
    else{
        if(together.size()==m){
            int last = together.back();
             last-=1;
             hour = last/60;
             minute = last%60;
        }
        else{
             hour = last_shuttle/60;
             minute = last_shuttle%60;
        }
    }

    answer = changed(hour,minute);
    return answer;
}