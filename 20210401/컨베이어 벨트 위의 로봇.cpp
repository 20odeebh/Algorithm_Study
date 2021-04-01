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
1.��Ʈ�� �� ĭ ���� �ִ� �κ���� �Բ� �� ĭ ȸ���Ѵ�. ������ ��ġ�� �ִ� �κ��� ������.
2.���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�.
-�κ��� �̵��ϱ� ���ؼ��� �κ��� ������ ��ġ�� �ƴϰ�, �̵��Ϸ��� ĭ�� �κ��� ������, �� ĭ�� �������� 1 �̻� ���� �־�� �Ѵ�.
3.�ø��� ��ġ�� �ִ� ĭ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
4.�������� 0�� ĭ�� ������ K�� �̻��̶�� ������ �����Ѵ�. �׷��� �ʴٸ� 1������ ���ư���.
*/
// ���� ������ �ʹ� �̻��ϴ�

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
	//dq[0] -= 1; // ��ó�� �κ� �ø���
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
		if (dq[i] == 0 || robot[i]) continue; // ���� �� ��
		if (robot[i - 1])
		{
			dq[i] -= 1;
			robot[i] = true;
			robot[i - 1] = false;
		}
	}
	robot[n - 1] = false; // �������� ��ġ
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

	for (int i = n - 1; i >= 1; --i) robot[i] = robot[i - 1]; // ��Ʈ�� ���� �κ��� �̵� (1~n�� 0~n-1�� ���)
	robot[0] = false;
	robot[n - 1] = false; // n-1 ����������ġ
	
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