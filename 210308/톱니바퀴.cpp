#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

deque <int> dq[4];

int k;

/*
void cal() {
// 조건
// 1. 인접한 두 개의 블럭이 2이상 차이나면 안됨
// 2. 경사로를 놓은 후 다음 블럭과 높이 차이가 나면 안됨
// 3. 경사로를 놓은 후 블럭의 높이 차이가 있는 블럭이 있으면 길이가 L이상 차이나야한다.
for (int i = 0; i < n; i++) {
int cnt = 0;
bool flag = true;
for (int j = 0; j < n-1; j++) {
int gap = arr[i][j] - arr[i][j + 1];
if (abs(gap) > 1) {
flag = false;
break;
}
// 내리막길
if (gap == 1) {
cnt = 0;
int val = arr[i][j + 1];
for (int k = j + 1; k < n; k++) {
if (val == arr[i][k])
cnt++;
else
break;
}
if (cnt < l)
{
flag = false;
break;
}
else if (cnt == l) {
if (arr[i][j + 1 + cnt] > val) {
cout << "왜" << val << ' ' <<  arr[i][j + 1 + cnt] << endl;
flag = false;
break;
}
}
else {
j = j + 1 + cnt;
}
}
// 오르막길
if (gap == -1) {
if (cnt+1 < l)
{
flag = false;
break;
}
}
if (gap == 0)
cnt++;
}
if (flag) {
cout << i << endl;
res++;
}
}
}
*/

bool visited[4] = { false, };

void move(int num, int dir) {
	visited[num] = true;
	int left = num - 1;
	int right = num + 1;
	//cout << left << ' ' << num << ' ' << right << endl;
	//cout << dq[left][2] << ' ' << dq[num][6] << ' ' << dq[num][2] << ' ' << dq[right][6] << endl;
	if (left >= 0 && !visited[left] && (dq[left][2] != dq[num][6])) {
		move(left, dir*(-1));
	}
	if (right < 4 && !visited[right] && (dq[num][2] != dq[right][6])) {
		move(right, dir*(-1));
	}
	// 시계 방향
	if (dir == 1) {
		int e = dq[num].back();
		dq[num].push_front(e);
		dq[num].pop_back();
	}
	// 반시계 방향
	else {
		int f = dq[num].front();
		dq[num].push_back(f);
		dq[num].pop_front();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			dq[i].push_back(str[j]-'0');
		}
	}

	cin >> k;
	while (k--)
	{
		for (int i = 0; i < 4; i++)
			visited[i] = false;

		int num, dir;
		cin >> num >> dir;
		// idx 맞춰주기
		move(num-1, dir);
	}

	int total = 0;
	for (int i = 0; i < 4; i++) {
		if (dq[i][0] == 1)
			total += pow(2, i);
	}

	cout << total;


}