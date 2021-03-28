#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//3씩 나누면서 
//나머지가 0이면 몫-1, answer에는 4 추가
//나머지가 1이면 몫 그대로, answer에는 1추가
//나머지가 2이면 몫 그대로, answer에는 2추가
string solution(int n) {
	string answer = "";
	while (n > 3) {
		if (n % 3) {
			answer += (char)(n % 3 + '0');
			n /= 3;
		}
		else {
			answer += '4';
			n /= 3;
			n--;
		}
	}
	if (n == 3)answer += '4';
	else answer += (char)(n + '0');
	reverse(answer.begin(), answer.end());
	return answer;
}