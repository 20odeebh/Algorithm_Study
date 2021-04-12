#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include<functional>
#include <set>
 
using namespace std;
int t;
unordered_map<char, int> m;
 
bool isNum(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}
int make_num(string str) {
    // str을 10진수 숫자로 나타내기
    int total = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        int tmp;
        if (isNum(str[i]))
            tmp = str[i] - '0';
        else
            tmp = m[str[i]];
        total += tmp*pow(16, str.size() - i - 1);
    }
    return total;
}
 
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
    //freopen("input.txt", "r", stdin);
    for (int i = 10; i < 16; i++) {
        m[char('A' + i - 10)] = i;
    }
     
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        deque<char> dq(str.begin(), str.end());
        int cnt = n / 4; // cnt만큼 회전하기
        map<int,string> tmp_map;
        for (int i = 0; i < n; i += cnt) {
            string tmp_str;
            for (int j = i; j < i+cnt; j++) {
                tmp_str += dq[j];
            }
            tmp_map.insert({ make_num(tmp_str),tmp_str });
        }
        for (int i = 0; i < cnt; i++) {
            // 회전
            int tmp = dq.back();
            dq.pop_back();
            dq.push_front(tmp);
            for (int i = 0; i < n; i += cnt) {
                string tmp_str;
                for (int j = i; j < i + cnt; j++) {
                    tmp_str += dq[j];
                }
                tmp_map.insert({ make_num(tmp_str),tmp_str });
            }
        }
        vector<pair<int, string>>v(tmp_map.begin(), tmp_map.end());
        cout << '#' << test_case << ' ' <<  v[v.size()-k].first << '\n';
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}