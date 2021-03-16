#include <iostream>
using namespace std;
int N;
int recur(int num)
{
	if (num == 0)
		return 1;
	else if (num < 0)
		return 0;
	int temp = 0;
	temp += recur(num - 1);
	temp += recur(num - 2);
	temp += recur(num - 3);
	return temp;
}
int main()
{
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		printf("%d\n", recur(num));
	}
	return 0;
}