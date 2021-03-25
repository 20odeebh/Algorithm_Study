#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>

using namespace std;
// 조건
// 1. 각 나라 승무패 합이 5 
// 2. 총 승 == 총 패
// 3. 승 무 패 0에서 5까지 !
// 4. 무승부는 
struct INFO {
	int win, tie, lose;
};
vector<INFO> res;
vector<int> tmp;
vector<pair<int, int>> cmp;
int arr[18];
set<string> s;
string cur;
bool flag = true;

// 두 나라 경쟁 조합 경우의 수 구하기
void dfs(int idx) {
	if (tmp.size() == 2) {
		cmp.push_back({ tmp[0],tmp[1] });
		return;
	}
	for (int i = idx; i < 6; i++) {
		tmp.push_back(i);
		dfs(i + 1);
		tmp.pop_back();
	}
}

void goGame(int idx) {
	// 같은 것을 찾았으면 바로 return 하기 위한 전역변수
	if (flag)
		return;
	// 15번의 경기를 모두 끝냈을 경우
	if (idx == 15) {
		for (int i = 0; i < 6; i++) {
			if (arr[3*i] != res[i].win)
				return;
			if (arr[3 * i + 1] != res[i].tie)
				return;
			if (arr[3 * i + 2] != res[i].lose)
				return;
		}
		flag = true;
		return;
	}
	// 각각 승,무승부,패로 모든 경우의 수 구하기
	int c1 = cmp[idx].first;
	int c2 = cmp[idx].second;
	// c1 > c2
	res[c1].win++;
	res[c2].lose++;
	goGame(idx + 1);
	res[c1].win--;
	res[c2].lose--;

	// c1 == c2
	res[c1].tie++;
	res[c2].tie++;
	goGame(idx + 1);
	res[c1].tie--;
	res[c2].tie--;

	// c1 < c2
	res[c1].lose++;
	res[c2].win++;
	goGame(idx + 1);
	res[c1].lose--;
	res[c2].win--;

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	dfs(0);

	for (int i = 0; i < 6; i++)
		res.push_back({ 0,0,0 });


	for (int i = 0; i < 4; i++) {
		flag = false;

		int total_win = 0;
		int total_tie = 0;
		int total_lose = 0;

		for (int j = 0; j < 18; j++) {
			cin >> arr[j];
			if (arr[j] >= 6 || arr[j] < 0)
				flag = false;
			if (j % 3 == 0)
				total_win += arr[j];
			else if (j % 3 == 1)
				total_tie += arr[j];
			else
				total_lose += arr[j];
		}
		// 이미 조건에 맞지 않는 경우에는 굳이 탐색하지 않고 바로 false 반환
		if ((total_win + total_tie + total_lose != 30) || (total_win!=total_lose))
			flag = false;
		else {
			goGame(0);
		}
		if (flag)
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}
}
