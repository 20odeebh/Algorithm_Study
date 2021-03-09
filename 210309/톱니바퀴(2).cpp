#include <iostream>
#include <string>
#include <deque>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;
vector<deque<int>> wheel;
int K;
vector<bool> visit;
void rotate(int start, int dir)
{
	if (visit[start] == false)
		visit[start] = true;
	else
		return;
	if (start + 1 < K) {
		if (wheel[start][2] != wheel[start + 1][6]) {
			rotate(start + 1, -dir);
		}
	}
	if (start - 1 >= 0) {
		if (wheel[start][6] != wheel[start - 1][2]) {
			rotate(start - 1, -dir);
		}
	}
	int temp;
	if (dir == -1) {
		temp = wheel[start].front();
		wheel[start].pop_front();
		wheel[start].push_back(temp);
	}
	else {
		temp = wheel[start].back();
		wheel[start].pop_back();
		wheel[start].push_front(temp);
	}
}
int summation()
{
	int sum = 0;
	for (int i = 0; i < K; i++) {
		if (wheel[i][0] == 1)
			sum++;
	}
	return sum;
}
int main()
{
	cin >> K;
	wheel = vector<deque<int>>(K, deque<int>());
	for (int i = 0; i < K; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			wheel[i].push_back(temp[j] - '0');
	}
	int tc, start, dir;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &start, &dir);
		visit = vector<bool>(K, false);
		rotate(start - 1, dir);
	}
	int answer = summation();
	printf("%d\n", answer);
	return 0;
}