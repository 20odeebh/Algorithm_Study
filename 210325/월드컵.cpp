#include <iostream>

using namespace std;
 
int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 }, team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
int answer[4], math[6][3], result[6][3];
 
void go(int t, int round){   
    if(round == 15){     
        if(answer[t]) return;
 
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 3; c++){               
                if(math[r][c] != result[r][c])
                    return;
            }
        }             
        answer[t] = 1;
        return;
    }
            
    int t1 = team1[round];
    int t2 = team2[round];
 
    result[t1][0]++; result[t2][2]++;
    go(t, round + 1);
    result[t1][0]--; result[t2][2]--;
 
    result[t1][1]++; result[t2][1]++;
    go(t, round + 1);
    result[t1][1]--; result[t2][1]--;
 
    result[t1][2]++; result[t2][0]++;
    go(t, round + 1);
    result[t1][2]--; result[t2][0]--;
}
 
 
int main() {  
    for(int i=0; i<4; i++){
        for(int r=0; r<6; ++r){
            for(int c=0; c<3; c++){
                cin >> math[r][c];
            }
        }
        go(i, 0);
    }
 
    for(int i=0; i<4; i++)
        cout << answer[i] << ' ';
}
