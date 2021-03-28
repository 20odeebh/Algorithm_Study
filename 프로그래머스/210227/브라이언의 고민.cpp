#include <bits/stdc++.h>
using namespace std;
int n;
bool check[130];
string s;
bool isLower(char c) {
    if (c >= 'a' && c <= 'z')return true;
    return false;
}
//l ~  r 구간이 규칙1이거나 , 단순한 대문자 스트링이면 true 반환
bool isAns(int l, int r) {
    if (l > r)return false;
    //소문자가 한개라도 있는지 체크
    bool flag = true;
    for (int i = l; i <= r; i++) {
        if (isLower(s[i])) {
            flag = false;
            break;
        }
    }
    if (flag)return true;
    //소문자가 한개라도 있지만 길이가 1이라면 false
    if (l == r)return false;

    if (isLower(s[l + 1]) == false)return false;
    char lowerC = s[l + 1];
    if (check[lowerC])return false;
    check[lowerC] = true;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (cnt % 2) {
            if (s[i] != lowerC)return false;
        }
        else {
            if (isLower(s[i]))return false;
        }
        cnt++;
    }
    return true;
}
string solution(string st) {
    string answer = "";
    s = st;
    for (int i = 'a'; i <= 'z'; i++)check[i] = false;
    n = s.size();
    int start = 0, anscnt = 0;
    while (start < n) {
        cout << start << ' ' << s[start] << '\n';
        //시작이 소문자일 경우 앞뒤 끝 소문자의 인덱스를찾아서
        //그 사이가 규칙1이 적용된 문자열이거나 전부 대문자인 문자열이면 단어가 된다.
        if (isLower(s[start])) {
            //이미 사용한 소문자라면 invalid
            if (check[s[start]])return "invalid";
            check[s[start]] = true;
            int l = start, r = -1, l2 = l + 1;
            while (l2 < n) {
                if (s[l2] == s[start]) {
                    r = l2;
                    break;
                }
                l2++;
            }
            //같은 소문자가 없거나 붙어있는 소문자인경우
            if (r == -1 || l + 1 == r)return "invalid";
            if (isAns(l + 1, r - 1)) {
                string temp = "";
                for (int i = l + 1; i < r; i++) {
                    if (isLower(s[i]) == false) {
                        temp += s[i];
                    }
                }
                if (anscnt) {
                    answer += ' ';
                    answer += temp;
                }
                else {
                    answer += temp;
                    anscnt++;
                }
                start = r + 1;
            }
            else return "invalid";
        }
        else {
            //시작이 대문자일경우 일단 대문자 바로 뒤에 소문자일때까지 대문자는 따로 빼준다
            int start2 = start + 1;
            if (start2 == n) {
                if (anscnt) {
                    answer += ' ';
                    answer += s[start];
                }
                else {
                    answer += s[start];
                }
                break;
            }
            if (isLower(s[start2])) {
                //AaBa
                //AaBaC
                //소문자가 1개면 무조건 다음에 대문자가 와야함
                //소문자가 2개면 따로 1글자씩 빼도됨
                //소문자가 3개이상이면 무조건 규칙1
                char lowerC = s[start2];
                int start3 = start2 + 1;
                if (start3 >= n)return "invalid";
                if (isLower(s[start3]))return "invalid";
                if (check[lowerC])return "invalid";
                check[lowerC] = true;
                int tl = start2, tr = -1, tl2 = n - 1;
                while (tl2 > start2) {
                    if (s[tl2] == lowerC) {
                        tr = tl2;
                        break;
                    }
                    tl2--;
                }
                if (tr != -1) {
                    if (isAns(tl + 1, tr - 1)) {
                        if (anscnt)answer += ' ';
                        else anscnt++;
                        answer += s[start];
                        string temp = "";
                        for (int i = tl; i <= tr; i++) {
                            if (isLower(s[i]) == false)temp += s[i];
                        }
                        if (anscnt)answer += ' ';
                        else anscnt++;
                        answer += temp;
                        start = tr + 1;
                        continue;
                    }
                }
                int lowerCnt = 1, cnt = 1;
                start3++;
                int l = start, r = start + 2;
                while (start3 < n) {
                    if (s[start3] == lowerC) {
                        lowerCnt++;
                        if (start3 + 1 == n)return "invalid";
                        if (isLower(s[start3 + 1])) {
                            if (lowerCnt != 2)return "invalid";
                            r = start3;
                            break;
                        }
                        else {
                            start3 += 2;
                            if (start3 == n) {
                                r = start3 - 1;
                                break;
                            }
                        }
                    }
                    //AaBa
                    //AaBaCaA
                    else {
                        r = start3 - 1;
                        break;
                    }
                }
                if (isLower(s[r])) {
                    if (anscnt) {
                        answer += ' ';
                    }
                    else {
                        anscnt++;
                    }
                    answer += s[l];
                    answer += ' ';
                    answer += s[l + 2];
                }
                else {
                    string temp = "";
                    for (int i = l; i <= r; i++) {
                        if (isLower(s[i]) == false)temp += s[i];
                    }
                    if (anscnt) {
                        answer += ' ';
                        answer += temp;
                    }
                    else {
                        answer += temp;
                        anscnt++;
                    }
                }
                start = r + 1;
            }
            else {
                if (anscnt) {
                    answer += ' ';
                    answer += s[start];
                }
                else {
                    anscnt++;
                    answer += s[start];
                }
                start++;
                continue;
            }

        }
    }
    return answer;
}