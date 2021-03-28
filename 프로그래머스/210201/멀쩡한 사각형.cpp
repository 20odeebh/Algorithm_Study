#include <algorithm>
using namespace std;

long long GCD(int a, int b) {
	if (b == 0)return a;
	else return GCD(b, a % b);
}

long long solution(int w, int h) {
	long long answer = 1;
	if (w > h)swap(w, h);
	long long g = GCD(w, h);
	//최대공약수가 1이 아닌 사각형은 동일 패턴이 g*g 갯수 만큼 반복됨
	long long w2 = w / g, h2 = h / g;
	long long total = (long long)w * (long long)h;
	//미니 패턴안에서 잘라지는 사각형의 갯수
	long long mini = w2+h2-1LL;
	//선에 그이는 사각형의 패턴은 g개만큼 반복되므로 g개를 곱해준다.
	answer = total - mini * g;

	return answer;
}