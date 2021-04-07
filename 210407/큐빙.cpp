// 큐빙

#include <stdio.h>

int tc, n;
char color[6] = { 'r','b','o','g','w','y' };
char cube[6][9];
char command[3];

void init() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 9; j++)
				cube[i][j] = color[i];
}

void turn_left(int num) {
	int tmp[9];
	for (int i = 0; i < 9; i++) tmp[i] = cube[num][i];
	int idx = 0;
	for (int i = 2; i >= 0; i--)
		for (int j = 0; j < 3; j++)
			cube[num][idx++] = tmp[3 * j + i];
}

void turn_right(int num) {
	int tmp[9];
	for (int i = 0; i < 9; i++) tmp[i] = cube[num][i];
	int idx = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 2; j >= 0; j--)
			cube[num][idx++] = tmp[3 * j + i];
}

void F(char& dir) {
	int tmp[3];
	if (dir == '+') {
		turn_right(0);
		for (int i = 0; i < 3; i++) tmp[i] = cube[1][i * 3];
		for (int i = 0; i < 3; i++) cube[1][i * 3] = cube[4][i + 6];
		for (int i = 0; i < 3; i++) cube[4][i + 6] = cube[3][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[3][(2 - i) * 3 + 2] = cube[5][2 - i];
		for (int i = 0; i < 3; i++) cube[5][2 - i] = tmp[i];
	}
	else {
		turn_left(0);
		for (int i = 0; i < 3; i++) tmp[i] = cube[1][i * 3];
		for (int i = 0; i < 3; i++) cube[1][i * 3] = cube[5][2 - i];
		for (int i = 0; i < 3; i++) cube[5][2 - i] = cube[3][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[3][(2 - i) * 3 + 2] = cube[4][i + 6];
		for (int i = 0; i < 3; i++) cube[4][i + 6] = tmp[i];
	}
}

void R(char& dir) {
	int tmp[3];
	if (dir == '+') {
		turn_right(1);
		for (int i = 0; i < 3; i++) tmp[i] = cube[2][i * 3];
		for (int i = 0; i < 3; i++) cube[2][i * 3] = cube[4][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[4][(2 - i) * 3 + 2] = cube[0][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[0][(2 - i) * 3 + 2] = cube[5][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[5][(2 - i) * 3 + 2] = tmp[i];
	}
	else {
		turn_left(1);
		for (int i = 0; i < 3; i++) tmp[i] = cube[2][i * 3];
		for (int i = 0; i < 3; i++) cube[2][i * 3] = cube[5][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[5][(2 - i) * 3 + 2] = cube[0][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[0][(2 - i) * 3 + 2] = cube[4][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[4][(2 - i) * 3 + 2] = tmp[i];
	}
}

void B(char& dir) {
	int tmp[3];
	if (dir == '+') {
		turn_right(2);
		for (int i = 0; i < 3; i++) tmp[i] = cube[3][i * 3];
		for (int i = 0; i < 3; i++) cube[3][i * 3] = cube[4][2 - i];
		for (int i = 0; i < 3; i++) cube[4][2 - i] = cube[1][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[1][(2 - i) * 3 + 2] = cube[5][i + 6];
		for (int i = 0; i < 3; i++) cube[5][i + 6] = tmp[i];
	}
	else {
		turn_left(2);
		for (int i = 0; i < 3; i++) tmp[i] = cube[3][i * 3];
		for (int i = 0; i < 3; i++) cube[3][i * 3] = cube[5][i + 6];
		for (int i = 0; i < 3; i++) cube[5][i + 6] = cube[1][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[1][(2 - i) * 3 + 2] = cube[4][2 - i];
		for (int i = 0; i < 3; i++) cube[4][2 - i] = tmp[i];
	}
}

void L(char& dir) {
	int tmp[3];
	if (dir == '+') {
		turn_right(3);
		for (int i = 0; i < 3; i++) tmp[i] = cube[0][i * 3];
		for (int i = 0; i < 3; i++) cube[0][i * 3] = cube[4][3 * i];
		for (int i = 0; i < 3; i++) cube[4][3 * i] = cube[2][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[2][(2 - i) * 3 + 2] = cube[5][3 * i];
		for (int i = 0; i < 3; i++) cube[5][3 * i] = tmp[i];
	}
	else {
		turn_left(3);
		for (int i = 0; i < 3; i++) tmp[i] = cube[0][i * 3];
		for (int i = 0; i < 3; i++) cube[0][i * 3] = cube[5][i * 3];
		for (int i = 0; i < 3; i++) cube[5][i * 3] = cube[2][(2 - i) * 3 + 2];
		for (int i = 0; i < 3; i++) cube[2][(2 - i) * 3 + 2] = cube[4][3 * i];
		for (int i = 0; i < 3; i++) cube[4][3 * i] = tmp[i];
	}
}

void U(char& dir) {
	int tmp[3];
	if (dir == '+') {
		turn_right(4);
		for (int i = 0; i < 3; i++) tmp[i] = cube[1][2 - i];
		for (int i = 0; i < 3; i++) cube[1][2 - i] = cube[2][2 - i];
		for (int i = 0; i < 3; i++) cube[2][2 - i] = cube[3][2 - i];
		for (int i = 0; i < 3; i++) cube[3][2 - i] = cube[0][2 - i];
		for (int i = 0; i < 3; i++) cube[0][2 - i] = tmp[i];
	}
	else {
		turn_left(4);
		for (int i = 0; i < 3; i++) tmp[i] = cube[1][2 - i];
		for (int i = 0; i < 3; i++) cube[1][2 - i] = cube[0][2 - i];
		for (int i = 0; i < 3; i++) cube[0][2 - i] = cube[3][2 - i];
		for (int i = 0; i < 3; i++) cube[3][2 - i] = cube[2][2 - i];
		for (int i = 0; i < 3; i++) cube[2][2 - i] = tmp[i];
	}
}

void D(char& dir) {
	int tmp[3];
	if (dir == '+') {
		turn_right(5);
		for (int i = 0; i < 3; i++) tmp[i] = cube[1][i + 6];
		for (int i = 0; i < 3; i++) cube[1][i + 6] = cube[0][i + 6];
		for (int i = 0; i < 3; i++) cube[0][i + 6] = cube[3][i + 6];
		for (int i = 0; i < 3; i++) cube[3][i + 6] = cube[2][i + 6];
		for (int i = 0; i < 3; i++) cube[2][i + 6] = tmp[i];
	}
	else {
		turn_left(5);
		for (int i = 0; i < 3; i++) tmp[i] = cube[1][i + 6];
		for (int i = 0; i < 3; i++) cube[1][i + 6] = cube[2][i + 6];
		for (int i = 0; i < 3; i++) cube[2][i + 6] = cube[3][i + 6];
		for (int i = 0; i < 3; i++) cube[3][i + 6] = cube[0][i + 6];
		for (int i = 0; i < 3; i++) cube[0][i + 6] = tmp[i];
	}
}

void print() {
	for (int i = 0; i < 9; i++) {
		if (i && i % 3 == 0) printf("\n");
		printf("%c", cube[4][i]);
	}
	printf("\n");
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		init();
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", command);
			switch (command[0])
			{
			case 'F': F(command[1]); break;
			case 'R': R(command[1]); break;
			case 'B': B(command[1]); break;
			case 'L': L(command[1]); break;
			case 'U': U(command[1]); break;
			case 'D': D(command[1]); break;
			}
		}
		print();
	}
}