#include <bits/stdc++.h>
using namespace std;
bool d[2501][2501];
//다이나믹 프로그래밍
//d[i][j] = i~j 문자열이 팰린드롬이면 true
//d[i][j] 는 s[i] == s[j] 이고 d[i+1][j-1]이 ture일때 팰린드롬이 된다.
int solution(string s)
{
    int answer = 1;
    int n = s.size();
    for (int i = 0; i < n; i++)d[i][i] = true;
    int n2 = n - 1;
    for (int i = 0; i < n2; i++) {
        if (s[i] == s[i + 1]) {
            d[i][i + 1] = true;
            answer = 2;
        }
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < s.size(); j++) {
            int l = j, r = j + i;
            if (r >= s.size())break;
            if (s[l] == s[r]) {
                if (d[l + 1][r - 1]) {
                    d[l][r] = true;
                    answer = i + 1;
                }
            }
        }
    }

    return answer;
}