#include<iostream>
#include <vector>
 
using namespace std;
 
typedef struct cell{
    bool isEmpty, isAlive;
    int aliveTime, refreshTime, HP;
}cell;
 
cell map[350][350];
 
typedef struct dir{
    int dr, dc;
}dir;
 
dir direction[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
 
int N, M, K, T;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> K;
        cell a;
        a.isEmpty = true;
        a.isAlive = false;
        a.aliveTime = -1;
        a.refreshTime = -1;
        a.HP = -1;
         
        for (int i = 0; i < 350; i++){
            for (int j = 0; j < 350; j++){
                map[i][j] = a;
            }
        }        
         
        for (int i = 150; i < 150 + N; i++){
            for (int j = 150; j < 150 + M; j++){
                int hp;
                cin >> hp;
                 
                if (hp == 0){
                    continue;
                }
                 
                else{
                    map[i][j].HP = hp;
                    map[i][j].isAlive = true;
                    map[i][j].isEmpty = false;
                    map[i][j].refreshTime = hp;
                    map[i][j].aliveTime = hp;
                }
            }
        }
         
        int time = 0;
        vector<pair<int, pair<int, int> > > v;
  
        while (true){
            time++;
            for (int r = 0; r < 350; r++){
                for (int c = 0; c < 350; c++){
                    if (map[r][c].isAlive){
                        if (map[r][c].refreshTime > 0){
                            map[r][c].refreshTime--;
                            continue;
                        }
                         
                        else if (map[r][c].refreshTime == 0 && map[r][c].aliveTime > 0){
                            map[r][c].aliveTime--;
                            if (map[r][c].aliveTime == 0) map[r][c].isAlive = false;
                             
                            if (map[r][c - 1].isEmpty || map[r][c + 1].isEmpty || map[r + 1][c].isEmpty || map[r - 1][c].isEmpty){
                                for (int next = 0; next < 4; next++){
                                    int nr = r + direction[next].dr;
                                    int nc = c + direction[next].dc;
                                     
                                    if (map[nr][nc].isEmpty && map[nr][nc].HP < map[r][c].HP){ 
                                        int erase_val = map[nr][nc].HP;
                                        map[nr][nc].HP = map[r][c].HP;
                                        v.push_back(make_pair(map[r][c].HP, make_pair(nr, nc)));
                                         
                                        for (int k = 0; k < v.size(); k++){
                                            if (v[k].second.first == nr && v[k].second.second == nc && v[k].first == erase_val){
                                                    v.erase(v.begin() + k);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
         
            for (int vidx = 0; vidx < v.size(); vidx++){
                int r = v[vidx].second.first;
                int c = v[vidx].second.second;
                int val = v[vidx].first;
                 
                cell a;
                a.aliveTime = val;
                a.HP = val;
                a.refreshTime = val;
                a.isAlive = true;
                a.isEmpty = false;
                map[r][c] = a;
            }
            v.clear();
             
            if (time == K){
                int sum = 0;
                for (int r = 0; r < 350; r++){
                    for (int c = 0; c < 350; c++){
                        if (map[r][c].isAlive) sum++;
                    }
                }
                cout << "#" << test_case  << " " << sum << '\n';
                break;
            }
        }
    }
    return 0;
}
