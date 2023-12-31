#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5];
char* strAnimal[10]; // 동물 이름 배열
int checkAnimal[4][5]; // 카드 뒷면, 앞면 확인 배열 선언

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();

int main4(void) {
	int failCount = 0;
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();
	shuffleAnimal();

	while (1) {
		int select1 = 0;
		int select2 = 0;
		printAnimals();
		printQuestion();
		printf("\n뒤집을 카드 2장을 고르세요. 예 12 4 -> ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) {
			continue;
		}

		// 입력받은 카드 번호를 x, y 좌표로 반환
		int firstSelectX = conv_pos_x(select1);
		int firstSelectY = conv_pos_y(select1);
		int secondSelectX = conv_pos_x(select2);
		int secondSelectY = conv_pos_y(select2);

		if ((checkAnimal[firstSelectX][firstSelectY] == 0
			&& checkAnimal[secondSelectX][secondSelectY] == 0
			&& (arrayAnimal[firstSelectX][firstSelectY] == arrayAnimal[secondSelectX][secondSelectY]))) {
			// 두 카드가 같은 동물이고 뒷면인 경우
			printf("\n\n빙고! %s 발견\n\n", strAnimal[arrayAnimal[firstSelectX][firstSelectY]]);
			checkAnimal[firstSelectX][firstSelectY] = 1;
			checkAnimal[secondSelectX][secondSelectY] = 1;
		}
		else { // 두 카드가 다른 동물이거나 앞면인 경우
			printf("\n\n땡! 서로 다른 동물 카드거나 이미 뒤집힌 카드입니다.\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelectX][firstSelectY]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelectX][secondSelectY]]);
			printf("\n");
			failCount++;
		}

		if (foundAllAnimals() == 1) {
			printf("\n\n축하합니다. 모든 동물을 찾았습니다.\n");
			printf("총 %d번 실패하였습니다.\n", failCount);
			break;
		}
	}

	
	return 0;
}

void initAnimalArray() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			arrayAnimal[i][j] = -1; // 카드 뒷면 설정
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 2; ++j) {
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);
			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20;
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}

	return 0;
}

int conv_pos_x(int x) {
	return x / 5;
}

int conv_pos_y(int y) {
	return y % 5;
}

void printAnimals() {
	printf("\n 동물 위치를 보여줍니다.\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n");
}

void printQuestion() {
	printf("\n문제\n\n");
	int seq = 0;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (checkAnimal[i][j] == 1) { // 카드가  앞이면
				printf("%8s", strAnimal[arrayAnimal[i][j]]); // 동물 이름 출력
			}
			else {
				printf("%8d", seq); // 카드 번호 출력
			}
			seq++; // 다음 카드로 넘어가기
		}
		printf("\n");
	}
}

int foundAllAnimals() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (checkAnimal[i][j] == 0) {
				return 0; // 뒤집지 않은 카드가 있음
			}
		}
	}

	return 1; // 모든 카드 뒤집음
}