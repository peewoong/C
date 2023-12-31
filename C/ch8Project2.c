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
		printf("몇 번 상품을 구매하시겠습니까?(1-12) ");
		scanf_s("%d", &input);

		if (input > 12 || input < 1) {
			printf("상품 번호를 잘못 입력했습니다.\n");
			continue;
		}
		else {
			printf("구매하신 상품은 %2d.%5s입니다. 감사합니다.\n", input, items[input - 1]);
			exit(0);
		}
	}
}

void initArray() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			vendingMachine[i][j] = -1; // 카드 뒷면 설정
		}
	}
}

void printItems() {
	int num = 1;
	printf("전체 상품 목록을 출력합니다.\n");

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
	items[0] = "우유";
	items[1] = "커피";
	items[2] = "주스";
	items[3] = "탄산음료";
	items[4] = "칸칩";
	items[5] = "거북칩";
	items[6] = "감자칩";
	items[7] = "고구마칩";
	items[8] = "안타볼";
	items[9] = "초코버섯";
	items[10] = "가재깡";
	items[11] = "씨리얼";
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