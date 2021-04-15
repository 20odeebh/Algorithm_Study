#include <queue> 
#include <cmath> 
#include <iostream> 
#include <vector> 
  
using namespace std; 
 
vector<deque<int>> m; 
vector<bool> v; 
vector<int> nums, d; 
 
void find(int num, int dir) { 
    v[num] = 1; 
    nums.push_back(num); 
    d.push_back(dir); 
     
    if (num - 1 >= 0 && !v[num - 1] && m[num - 1][2] != m[num][6]) find(num - 1, -dir);  
    if (num + 1 < 4 && !v[num + 1] && m[num][2] != m[num + 1][6]) find(num + 1, -dir); 
    } 
 
void go() { 
    int len = nums.size(); 
     
    for (int i = 0; i < len; i++) { 
        if (d[i] == 1) { 
        m[nums[i]].push_front(m[nums[i]][7]); 
        m[nums[i]].pop_back(); 
        }
         
        else { 
        m[nums[i]].push_back(m[nums[i]][0]); 
        m[nums[i]].pop_front(); 
        } 
    } 
} 
 
int main(int argc, char **argv) { 
    int test_case; 
    int T, K; 
  
    cin >> T; 
    for (test_case = 1; test_case <= T; ++test_case) { 
 
        cin >> K;
        m.assign(4, deque<int>(8));
        for (int i = 0; i < 4; i++) { 
            for (int j = 0; j < 8; j++) { 
                cin >> m[i][j]; 
            } 
        } 
     
    for (int i = 0; i < K; i++) { 
        int num, dir; 
        cin >> num >> dir; 
        nums.clear(); 
        d.clear(); 
        v.assign(4, 0); 
        find(num - 1, dir); go(); 
    } 
     
    int answer = 0; 
    for (int i = 0; i < 4; i++) { 
        if (m[i][0]) answer += (int)pow(2, i); 
    }
     
    cout << "#" << test_case << " " << answer << endl; 
    } 
    return 0; 
}
