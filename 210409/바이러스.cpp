#include<bits/stdc++.h>

using namespace std;

int m, n;
bool visited[101];
vector<int> adj[101];

int dfs(int here) {   
    if (visited[here]) return 0;
    visited[here] = 1;
   
    int ret = 1;   
    for (auto there : adj[here]) {       
        ret += dfs(there);       
    }   
    return ret;
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(1) - 1 << '\n';
}
