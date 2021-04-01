#include <bits/stdc++.h>

using namespace std;

deque<int> naegu;
deque<bool> conveyer;

int n, k, step;

void rotate(){
    conveyer.push_front(conveyer.back());
    conveyer.pop_back();

    naegu.push_front(naegu.back());
    naegu.pop_back();
    conveyer[n - 1] = false;
}

void move(){
    for (int i = n - 2; i >= 0; i--) {
        if ((!conveyer[i + 1]) && (naegu[i + 1] > 0) && (conveyer[i])) {
            conveyer[i] = false;
            conveyer[i + 1] = true;
            naegu[i + 1]--;
        }
    }
    conveyer[n - 1] = false;
}

void robot(){
    if (!conveyer[0] && naegu[0] > 0) {
        conveyer[0] = true;
        naegu[0]--;
    }
}

int check(){
    int count_ = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (naegu[i] == 0)
            count_++;
    }
    return count_;
}

int main(){
    step = 1;

    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        int in;
        cin >> in;
        naegu.push_back(in);
        conveyer.push_back(false);
    }

    while (true) {
        rotate();
        move();
        robot();

        int c = check();
        if (c >= k) {
            cout << step << "\n";
            return 0;
        }
        step++;
    }
}
