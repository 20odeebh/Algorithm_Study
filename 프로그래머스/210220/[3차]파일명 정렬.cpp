#include <bits/stdc++.h>
using namespace std;
//구조체를 이용하여 정렬기준을 맞춘뒤 소트
struct file {
    string head;
    int number, tail;
    bool operator< (const file& p)const {
        if (head == p.head) {
            if (number == p.number) {
                return tail < p.tail;
            }
            return number < p.number;
        }
        return head < p.head;
    }
};
file a[1001];
bool isNumber(char c) {
    if (c >= '0' && c <= '9')return true;
    return false;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    int size = files.size();
    for (int i = 0; i < size; i++) {
        int start = 0;
        a[i].head = ""; a[i].number = 0; a[i].tail = i;
        while (start < files.size()) {
            if (isNumber(files[i][start]))break;
            if (files[i][start] >= 'a')a[i].head += (files[i][start] - 32);
            else a[i].head += files[i][start];
            start++;
        }
        int cnt = 0;
        while (start < files[i].size()) {
            if (isNumber(files[i][start]) == false)break;
            a[i].number *= 10;
            a[i].number += (files[i][start] - '0');
            start++;
            cnt++;
            if (cnt == 5)break;
        }
    }
    sort(a, a + size);
    for (int i = 0; i < size; i++) {
        answer.push_back(files[a[i].tail]);
    }
    return answer;
}