#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
//정답 참조
int N, M, K;
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
struct str {
    int y;
    int x;
    int age;
    str(int y, int x, int age) :y(y), x(x), age(age) {};
};

int main() {

    std::ios_base::sync_with_stdio(false);

    cin >> N >> M >> K;

    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0)); // 추가되는 양분의 양
    vector<vector<int>> map(N + 1, vector<int>(N + 1, 0)); //양분 정보
    vector<int> tree[11][11]; //나무의 나이 정보

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            map[i][j] = 5;
        }


    int r, c, age;
    for (int i = 1; i <= M; i++) {
        cin >> r >> c >> age;
        tree[r][c].push_back(age);
    }

    while (K--) {

        vector<str> dead_tree; //죽은 나무
        vector<str> growth_tree; //번식 나무

        //봄
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (tree[r][c].empty())
                    continue;

                vector<int> vec;
                sort(tree[r][c].begin(), tree[r][c].end());
                for (int k = 0; k < tree[r][c].size(); k++) {
                    age = tree[r][c][k];

                    if (map[r][c] >= age) {
                        map[r][c] -= age;
                        vec.push_back(age + 1);

                        if ((age + 1) % 5 == 0)
                            growth_tree.push_back(str(r, c, age + 1));
                    }
                    else {
                        dead_tree.push_back(str(r, c, age / 2));
                    }
                }

                tree[r][c] = vec;
            }
        }


        //여름(죽은 나무 양분 먹는다)
        for (int i = 0; i < dead_tree.size(); i++) {
            r = dead_tree[i].y;
            c = dead_tree[i].x;
            age = dead_tree[i].age;

            map[r][c] += age;
        }


        //가을(번식하는 나무)
        for (int i = 0; i < growth_tree.size(); i++) {

            r = growth_tree[i].y;
            c = growth_tree[i].x;

            for (int j = 0; j < 8; j++) {
                int ny = r + dy[j];
                int nx = c + dx[j];

                if (ny<1 || ny>N || nx<1 || nx>N)
                    continue;

                tree[ny][nx].push_back(1);
            }
        }

        //겨울(양분 추가)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                map[i][j] += A[i][j];

    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans += tree[i][j].size();

    cout << ans << endl;
    return 0;
}