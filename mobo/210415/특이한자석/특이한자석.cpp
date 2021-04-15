#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;
int T,N;
int magnet[6][10];//idx 1, 2, 3, 4
int update[5];//idx 1, 2, 3, 4
void init() {
	for (int i = 0; i < 10; i++) {
		magnet[0][i] = 2;
		magnet[5][i] = 2;
	}

	for (int i = 0; i < 5; i++) {
		update[i] = 0;
	}
}
void read() {
	scanf("%d", &N);
	for (int k = 1; k <= 4; k++) {
		for (int i = 1; i <= 8; i++) {
			scanf("%d", &magnet[k][i]);
		}
		magnet[k][0] = magnet[k][8];
		magnet[k][9] = magnet[k][1];
	}
}

void rotate(int idx,int r) {
	switch (r)
	{
	case 1:
		for (int i = 9; i > 0; i--) {
			magnet[idx][i] = magnet[idx][i - 1];
		}
		magnet[idx][0] = magnet[idx][8];
		break;
	case -1:
		for (int i = 0; i <= 8; i++) {
			magnet[idx][i] = magnet[idx][i + 1];
		}
		magnet[idx][9] = magnet[idx][1];
		break;
	default:
		break;
	}
}

int play() {
	int ret = 0;
	queue<int> myqueue; // To be rotated
	for (int i = 1; i <= N; i++) {
		memset(update, 0, sizeof(int) * 5);
		int idx, r;
		scanf("%d %d", &idx, &r);
		myqueue.push(make_pair(idx, r));
		for (int j = 1; j < 4; j++) {
			if (magnet[idx - 1][3] ^ magnet[idx][7] == 1) {

			}
		}
	}
	int oper = 1;
	for (int i = 1; i < 5; i++) {
		if (magnet[i][0] == 1) {
			ret += oper;
		}
		oper *= 2;
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
		cout << "#" << asd + 1 << " "<< play()<<endl;
	}


}
