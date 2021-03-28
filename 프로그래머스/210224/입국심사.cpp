#include <string>
#include <vector>

using namespace std;
// 걸리는 시간을 기준으로 이분탐색
// 걸리는 시간/심사시간 을 다 더하면 최종적으로 몇명을 심사했는지 나옴
// 심사인원이 더 작으면 시간을 늘려주는 방법
long long solution(int n, vector<int> times) {
    long long l = 1, r = 1000000000LL * 1000000000LL;
    int size = times.size();
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long tn = 0;
        for (int i = 0; i < size; i++) {
            tn += mid / times[i];
        }
        if (tn < n)l = mid + 1;
        else r = mid - 1;
    }

    return l;
}