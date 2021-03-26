#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {

    long long min = 1;

    int s = times.size();
    sort(times.begin(), times.end());

    long long max = (long long)(times[s-1]) * n;
    long long answer = max;

    while(min<=max){
        long long mid = (min+max)/2;
        long long sum = 0;
        for(int i=0; i<s; i++)
            sum += mid/times[i];
        if(n>sum) min = mid+1;
        else
        {
            if(mid <= answer)
                answer = mid;
            max = mid - 1;
        }
    }
    return answer;
}