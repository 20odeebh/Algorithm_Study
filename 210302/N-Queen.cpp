#include <string>
#include <vector>

using namespace std;
#define MAX_SIZE 12
int result = 0;
bool board[MAX_SIZE][MAX_SIZE];
bool IsPossible(int n, int row, int col)
{
	for (int i = 0; i < n; i++) {
		if (col == i)
			continue;
		if (board[row][i] == true)
			return false;
	}
	for (int i = 0; i < n; i++) {
		if (row == i)
			continue;
		if (board[i][col] == true)
			return false;
	}
	for (int i = 1; i < n; i++) {
		if (row - i < 0 || col - i < 0)
			break;
		if (board[row - i][col - i] == true)
			return false;
	}
	for (int i = 1; i < n; i++) {
		if (row + i >= n || col - i < 0)
			break;
		if (board[row + i][col - i] == true)
			return false;
	}
	return true;
}
void bf(int n, int nth)
{
	if (nth == n) {
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!IsPossible(n, i, nth))
			continue;
		board[i][nth] = true;
		bf(n, nth + 1);
		board[i][nth] = false;
	}
}
int solution(int n) {
	int answer = 0;
	bf(n, 0);
	answer = result;
	return answer;
}