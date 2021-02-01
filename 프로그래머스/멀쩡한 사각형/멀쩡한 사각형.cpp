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
	//�ִ������� 1�� �ƴ� �簢���� ���� ������ g*g ���� ��ŭ �ݺ���
	long long w2 = w / g, h2 = h / g;
	long long total = (long long)w * (long long)h;
	//�̴� ���Ͼȿ��� �߶����� �簢���� ����
	long long mini = w2+h2-1LL;
	//���� ���̴� �簢���� ������ g����ŭ �ݺ��ǹǷ� g���� �����ش�.
	answer = total - mini * g;

	return answer;
}