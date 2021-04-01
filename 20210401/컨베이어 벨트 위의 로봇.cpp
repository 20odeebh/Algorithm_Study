#include<iostream>
#include<deque>
#define max_n 100
using namespace std;
int n, k;
deque<int> dq;
int ans;
bool robot[max_n + 1];
void input();
void belt_move();
bool is_end();
void solution();
void robot_move();
void up_robot();
void print();
/*
1.벨트가 각 칸 위에 있는 로봇들과 함께 한 칸 회전한다. 내리는 위치에 있는 로봇은 내린다.
2.가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
-로봇이 이동하기 위해서는 로봇이 내리는 위치가 아니고, 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
3.올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
4.내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
*/
// 문제 설명이 너무 이상하다

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	//dq[0] -= 1; // 맨처음 로봇 올리기
	//robot[0] = true;

	while (1)
	{
		belt_move(); // 1
		//print();
		robot_move(); // 2
		//print();
		up_robot(); // 3
		//print();
		
		//cout << "\n\n";
		//getchar();

		++ans;
		if (is_end()) break; // 4
	}
}
void print()
{
	int dq_size = dq.size();
	cout << "belt\n";
	for (int i = 0; i < dq_size; ++i)
	{
		cout << dq[i] << ' ';
	}
	cout << '\n';
	cout << "robot\n";
	for (int i = 0; i < dq_size; ++i)
	{
		cout << robot[i] << ' ';
	}
	cout << '\n';
}
void up_robot()
{
	if (dq[0] != 0)
	{
		dq[0] -= 1;
		robot[0] = true;
	}
}
void robot_move()
{
	for (int i = n - 1; i >= 1; --i)
	{
		if (dq[i] == 0 || robot[i]) continue; // 다음 갈 곳
		if (robot[i - 1])
		{
			dq[i] -= 1;
			robot[i] = true;
			robot[i - 1] = false;
		}
	}
	robot[n - 1] = false; // 내려가는 위치
}
bool is_end()
{
	bool res = false;
	int sum = 0;
	int dq_size = dq.size();

	for (int i = 0; i < dq_size; ++i)
	{
		if (dq[i] == 0) ++sum;
	}
	if (sum >= k) res = true;

	return res;
}
void belt_move()
{
	int temp = dq.back();
	dq.pop_back();
	dq.push_front(temp);

	for (int i = n - 1; i >= 1; --i) robot[i] = robot[i - 1]; // 벨트랑 같이 로봇도 이동 (1~n을 0~n-1로 사용)
	robot[0] = false;
	robot[n - 1] = false; // n-1 내려가는위치
	
}
void input()
{
	cin >> n >> k;
	int size = 2 * n;
	for (int i = 1; i <= size; ++i)
	{
		int num;
		cin >> num;
		dq.push_back(num);
	}
}