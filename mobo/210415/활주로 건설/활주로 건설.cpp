#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
int N,M,T;
int pane[22][22];
void init() {
	memset(pane, 0, sizeof(int) * 22 * 22);
}
void read() {
	scanf("%d %d",&N,&M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d",&pane[i][j]);
		}
	}
}

int cal() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int now = pane[i][0];
		int length = 1;
		int flag = 1;
		for (int j = 1; j < N; j++) {
			if (pane[i][j] == now) {//높이 같음
				length++;
			}
			else if (now-pane[i][j]==1) {//1칸 하락
				if (length < 0) {
					flag = 0;
					break;
				}
				now = pane[i][j];
				length = 1 - M;
			}
			else if (now - pane[i][j] == -1) {//1칸 상승
				if (length >= M) {
					length = 1;
					now = pane[i][j];
				}
				else {//can not make
					flag = 0;
					break;
				}
			}
			else {//높이차 2칸 이상
				flag = 0;
				break;
			}
		}
		if (length < 0) {
			flag = 0;
		}
		ret += flag;
	}

	for (int i = 0; i < N; i++) {
		int now = pane[0][i];
		int length = 1;
		int flag = 1;
		for (int j = 1; j < N; j++) {
			if (pane[j][i] == now) {
				length++;
			}
			else if (now - pane[j][i] == 1) {//1칸 하락
				if (length < 0) {
					flag = 0;
					break;
				}
				length = 1 - M;
				now = pane[j][i];
			}
			else if (now - pane[j][i] == -1) {//1칸 상승
				if (length >= M) {
					length = 1;
					now = pane[j][i];
				}
				else {//can not make
					flag = 0;
					break;
				}
			}
			else {
				flag = 0;
				break;
			}
		}
		if (length < 0) {
			flag = 0;
		}
		ret += flag;
	}
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int asd = 0; asd < T; asd++) {
		init();
		read();
		cout<<"#"<<asd+1<<" " << cal()<<endl;
	}
}
