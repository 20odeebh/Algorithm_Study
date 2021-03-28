#include <bits/stdc++.h>
using namespace std;
//정답 로직 참조
//백트래킹
//모든 스트링을 숫자로 바꾼 뒤 dfs
//방문 체크는 간선마다 하며, 모든 간선과 모든 정점을 방문하면 true를 리턴하는 dfs 함수 사용
map<string, bool> string_check;
map<string, int> string_map;
map<pair<int, int>, bool> edge_check, edge_check2;
vector<string> v;
vector<int> graph[10001];
vector<string> answer;
int edgesize = 0, nowsize = 0;
//쭉 체크하다가 모든 간선과 정점을 방문하면 nowsize는 edgesize값이 되고, 그때 return true
//아니라면 answer와 nowsize의 정보를 빼고 return false
bool dfs(int start) {
    answer.push_back(v[start]);
    nowsize++;
    if (nowsize == edgesize)return true;
    int size = graph[start].size();
    for (int i = 0; i < size; i++) {
        if (edge_check[{start, i}] == false) {
            edge_check[{start, i}] = true;
            if (dfs(graph[start][i])) {
                return true;
            }
            edge_check[{start, i}] = false;
        }
    }
    nowsize--;
    answer.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    int size = tickets.size();
    edgesize = size + 1;
    //중복 제외한 스트링을 v 벡터에 PUSH
    for (int i = 0; i < size; i++) {
        for (auto s : tickets[i]) {
            if (string_check[s] == false) {
                string_check[s] = true;
                v.push_back(s);
            }
        }
    }

    //중복제외한 스트링의 번호를 새긴다.
    int vsize = v.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < vsize; i++) {
        string_map[v[i]] = i;
    }

    //번호로 그래프 형성
    for (int i = 0; i < size; i++) {
        graph[string_map[tickets[i][0]]].push_back(string_map[tickets[i][1]]);
    }
    for (int i = 0; i < vsize; i++)sort(graph[i].begin(), graph[i].end());
    for (int i = 0; i < vsize; i++) {
        cout << v[i] << " : ";
        for (int j = 0; j < graph[i].size(); j++) {

            cout << v[graph[i][j]] << ' ';
        }
        cout << '\n';
    }
    dfs(string_map["ICN"]);
    return answer;
}