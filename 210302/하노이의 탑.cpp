#include <bits/stdc++.h>

using namespace std;
 
vector<vector<int>> answer;
 
void hanoi(int num, int from, int by, int to)
{
    if(num == 1)
    {
        vector<int> temp;
        temp.push_back(from);
        temp.push_back(to);
        answer.push_back(temp);       
        return;
    }
    
    hanoi(num-1, from, to, by);
    
    vector<int> temp;
    temp.push_back(from);
    temp.push_back(to);
    answer.push_back(temp);
    
    hanoi(num-1, by, from, to);
}
 
vector<vector<int>> solution(int n) 
{
    hanoi(n, 1, 2, 3);    
    return answer;
}
