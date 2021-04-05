#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int N, M, T;
deque<int> circle[51];
void copy(deque<int>* src)
{
	for (int i = 0; i < N; i++)
		circle[i] = src[i];
}
int result()
{
	int size = circle[0].size(), sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size; j++) {
			if (circle[i][j] != -1)
				sum += circle[i][j];
		}
	}
	return sum;
}
void uniform()
{
	int size = circle[0].size(), cnt = 0;
	double aver = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size; j++) {
			if (circle[i][j] != -1) {
				aver += circle[i][j];
				cnt++;
			}
		}
	}
	aver /= cnt;
	deque<int> temp[51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size; j++) {
			if (circle[i][j] == -1)
				temp[i].push_back(-1);
			else if (aver < circle[i][j])
				temp[i].push_back(circle[i][j] - 1);
			else if (aver > circle[i][j])
				temp[i].push_back(circle[i][j] + 1);
			else
				temp[i].push_back(circle[i][j]);
		}
	}
	copy(temp);
}
bool remove()
{
	int size = circle[0].size();
	bool IsRemove = false;
	deque<int> temp[51];
	int up = -1, down = -1, left = -1, right = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size; j++) {
			int num = circle[i][j];
			if (num == -1) {
				temp[i].push_back(-1);
				continue;
			}
			up = i + 1 >= N ? -1 : circle[i + 1][j];
			down = i - 1 < 0 ? -1 : circle[i - 1][j];
			right = circle[i][(j + 1) % size];
			left = circle[i][(j + size - 1) % size];
			if (num == up || num == down || num == left || num == right) {
				IsRemove = true;
				temp[i].push_back(-1);
			}
			else
				temp[i].push_back(num);
		}
	}
	copy(temp);
	return IsRemove;
}
void rotate(int x, int d, int k)
{
	for (int i = 1; i <= N; i++) {
		if (i % x == 0) {
			auto& c = circle[i - 1];
			if (d == 0) {
				for (int j = 0; j < k; j++) {
					c.push_front(c.back());
					c.pop_back();
				}
			}
			else {
				for (int j = 0; j < k; j++) {
					c.push_back(c.front());
					c.pop_front();
				}
			}
		}
	}
	//지우지 않은 경우
	if (!remove())
		uniform();
}
int main()
{
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			circle[i].push_back(temp);
		}
	}
	int x, d, k;
	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		rotate(x, d, k);
	}
	printf("%d\n", result());
	return 0;
}