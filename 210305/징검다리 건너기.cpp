#include <bits/stdc++.h>

using namespace std;
bool binary_search(int mid,int k,vector<int>& v) {
    int cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] - mid <= 0)cnt++;
        else cnt = 0;
        if (cnt >= k)return true;
    }
    return false;
}
int solution(vector<int> stones, int k) {
    int first = 1;
    int last = *max_element(stones.begin(), stones.end());
    
    while (first <= last) {
        int mid = (first + last) / 2;
        if (binary_search(mid, k, stones)) {
            last = mid - 1;
        }
        else first = mid + 1;
    }

    return first;
}