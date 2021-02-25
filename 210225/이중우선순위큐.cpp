#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 그냥 vector, deque 사용하면 정렬 NlogN
// multiset or pq 사용해야 logN에 사용가능 

multiset <int> s;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(auto &k:operations){
        string str = k;
        char cmd = str[0];
        int num = stoi(str.substr(2));
        if(cmd=='I'){
            s.insert(num);
        }
        else{
            // 최댓값 삭제
            if(num==1 && !s.empty()){
                auto iter = s.end();
                iter--;
                s.erase(iter);
            }
            else if(num==-1 && !s.empty())
                s.erase(s.begin());
        }
    }
    
    if(s.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        auto iter = s.end();
        iter--;
        answer.push_back(*iter);
        answer.push_back(*(s.begin()));
    }
    
    return answer;
}