#include <stdio.h>
#include <time.h>
#include <stdio.h>

typedef struct {
	char* name;
	char* character;
	int age;
	int level;
} CAT;

CAT cats[5]; // 큰 상자에 있는 고양이 목록
int collection[5] = { 0,0,0,0,0 };

void initCats();
void printCat(int selected);
int checkCollection();

int main(void) {
	srand(time(NULL));
	initCats();

	while (1) {
		printf("두근두근! 어느 고양이의 집사가 될까요? \n엔터를 눌러 확인하세요!");
		getchar();
		int selected = rand() % 5;
		printCat(selected);

		collection[selected] = 1;
		int collectAll = checkCollection();

		if (collectAll == 1) {
			break; // 고양이 5마리를 모두 모으면 무한 반복문 탈출
		}
	}

	return 0;
}

void initCats() {
	cats[0].name = "A";
	cats[0].age = 5;
	cats[0].character = "온순함";
	cats[0].level = 1;

	cats[1].name = "B";
	cats[1].age = 3;
	cats[1].character = "까칠함";
	cats[1].level = 2;

	cats[2].name = "C";
	cats[2].age = 7;
	cats[2].character = "잠이 많음";
	cats[2].level = 3;

	cats[3].name = "D";
	cats[3].age = 2;
	cats[3].character = "시끄러움";
	cats[3].level = 4;

	cats[4].name = "E";
	cats[4].age = 1;
	cats[4].character = "늘 배고픔";
	cats[4].level = 5;
}

void printCat(int selected) {
	printf("고양이의 정보를 출력합니다\n");
	printf("이름 : %s\n", cats[selected].name);
	printf("나이 : %d\n", cats[selected].age);
	printf("특징 : %s\n", cats[selected].character);
	printf("레벨 : ");
	for (int i = 0; i < cats[selected].level; ++i) {
		printf("%s", "★");
	}
	printf("\n\n");
}

int checkCollection() {
	int collectAll = 1;
	printf("보유한 고양이 목록입니다. \n\n");
	for (int i = 0; i < 5; ++i) {
		if (collection[i] == 0) {
			printf("%10s", "(빈 상자)");
			collectAll = 0;
		}
		else {
			printf("%10s", cats[i].name);
		}
	}
	printf("\n\n");

	if (collectAll) {
		printf("\n축하합니다. 5마리의 고양이를 모두 모았어요. 열심히 키워주세요\n");
	}

	return collectAll;
}