#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//1~n까지의 최소공배수를 계산
int GCD(int a, int b) {
	if (b == 0)return a;
	else return GCD(b, a % b);
}
int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}
int solution(vector<int> arr) {
	int size = arr.size();
	if (size == 1)return arr[0];
	int start = LCM(arr[0], arr[1]);
	for (int i = 2; i < size; i++) {
		start = LCM(start, arr[i]);
	}
	return start;
}