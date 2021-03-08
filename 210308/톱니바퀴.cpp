#include <iostream>
#include <string>
#include <deque>
#include <cmath>
#include <string.h>
using namespace std;
deque<int> wheel[4];
bool visit[4] = { false, };
void rotate(int start, int dir)
{
	if (visit[start] == false)
		visit[start] = true;
	else
		return;
	if (start + 1 < 4) {
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
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1)
			sum += pow(2, i);
	}
	return sum;
}
int main()
{
	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			wheel[i].push_back(temp[j] - '0');
	}
	int tc, start, dir;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d %d", &start, &dir);
		rotate(start - 1, dir);
		memset(visit, false, sizeof(visit));
	}
	int answer = summation();
	printf("%d\n", answer);
	return 0;
}