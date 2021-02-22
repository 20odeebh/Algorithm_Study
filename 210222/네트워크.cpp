#include <string>
#include <vector>

using namespace std;
// dfs로 연결 네트워크 구하기 
vector<vector<int>> edge;
bool visited[201]={false,};
int N;

// 연결된 정점 모두 true로 바꾸기
void dfs(int num){
    for(int i=0;i<N;i++){
        if(i!=num && edge[num][i] && !visited[i]){
            visited[i]=true;
            dfs(i);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N=n;
    edge.assign(computers.begin(),computers.end());
    for(int i=0;i<N;i++){
        // 이미 방문한 정점이면 pass
        if(visited[i])
            continue;
        // 그렇지 않으면 네트워크 개수 갱신
        answer++;
        // i번째 정점과 연결된 정점 모두 true로 바꾸는 dfs
        dfs(i);
    }

    return answer;
}