#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int vendingMachine[3][4];
char* items[12];

void initArray();
void printItems();
void initItemName();
void shuffleItems();
int getEmptyPos();
int findX(int x);
int findY(int y);

int main5(void) {
	int input;
	srand((unsigned int)time(NULL));
	initArray();
	initItemName();
	shuffleItems();

	while (1) {
		printItems();
		printf("�� �� ��ǰ�� �����Ͻðڽ��ϱ�?(1-12) ");
		scanf_s("%d", &input);

		if (input > 12 || input < 1) {
			printf("��ǰ ��ȣ�� �߸� �Է��߽��ϴ�.\n");
			continue;
		}
		else {
			printf("�����Ͻ� ��ǰ�� %2d.%5s�Դϴ�. �����մϴ�.\n", input, items[input - 1]);
			exit(0);
		}
	}
}

void initArray() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			vendingMachine[i][j] = -1; // ī�� �޸� ����
		}
	}
}

void printItems() {
	int num = 1;
	printf("��ü ��ǰ ����� ����մϴ�.\n");

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			printf("%2d. %5s   ", num, items[vendingMachine[i][j]]);
			num++;
		}
		printf("\n");
	}
	printf("\n");
}

void initItemName() {
	items[0] = "����";
	items[1] = "Ŀ��";
	items[2] = "�ֽ�";
	items[3] = "ź������";
	items[4] = "ĭĨ";
	items[5] = "�ź�Ĩ";
	items[6] = "����Ĩ";
	items[7] = "����Ĩ";
	items[8] = "��Ÿ��";
	items[9] = "���ڹ���";
	items[10] = "�����";
	items[11] = "������";
}

void shuffleItems() {
	for (int i = 0; i < 12; ++i) {
		int pos = getEmptyPos();
		int x = findX(pos);
		int y = findY(pos);
		vendingMachine[x][y] = i;
	}
}

int getEmptyPos() {
	while (1) {
		int randPos = rand() % 20;
		int x = findX(randPos);
		int y = findY(randPos);

		if (vendingMachine[x][y] == -1) {
			return randPos;
		}
	}

	return 0;
}

int findX(int x) {
	return x / 4;
}

int findY(int y) {
	return y % 4;
}