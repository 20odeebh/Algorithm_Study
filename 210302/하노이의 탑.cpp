#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;


void move(int from, int to){
    answer.push_back({from, to});
    return;
}

void hanoi(int from, int via, int to, int n){
    // 기저사건
    if(n==1){
        move(from,to);
        return;
    }
    hanoi(from,to,via,n-1);
    move(from,to);
    hanoi(via,from,to,n-1);
}

vector<vector<int>> solution(int n) {
    hanoi(1,2,3,n);
    return answer;
}