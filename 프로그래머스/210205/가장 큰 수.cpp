#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//앞+뒤, 뒤+앞 더해서 소트
bool cmp(const int a, const int b) {
	string sa = to_string(a), sb = to_string(b);
	string sab = sa + sb, sba = sb + sa;
	for (int i = 0; i < sab.size(); i++) {
		if (sab[i] < sba[i])return true;
		if (sab[i] > sba[i])return false;
	}
	return a < b;
}
string solution(vector<int> numbers) {
	string answer = "";
	int size = numbers.size() - 1;
	bool flag = false;
	for (auto k : numbers) {
		if (k) {
			flag = true;
			break;
		}
	}
	if (flag == false)return "0";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = size; i >= 0; i--) {
		answer += to_string(numbers[i]);
	}
	return answer;
}
int main() {
	cout << solution({ 404,4044 }) << '\n';
}