#include <stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price; 
	char* company;
	struct GameInfo* friendGame;
};

typedef struct GameInformation {
	char* name;
	int year;
	int price;
	char* company;
	struct GameInfo* friendGame;
} GAME_INFO;

int main8(void) {
	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "한글 게임";
	game1.year = 2022;

	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2023;

	struct GameInformation game3;
	game3.name = "한글 게임3";

	printf("게임 이름 : %s\n", game1.name);
	printf("발매 연도 : %d\n", game1.year);
	printf("게임 이름 : %s\n", game2.name);
	printf("발매 연도 : %d\n", game2.year);

	return 0;
}

int main9(void) {
	struct GameInfo gameInfo1;
	gameInfo1.name = "나도게임";
	gameInfo1.year = 2022;
	gameInfo1.price = 50;
	gameInfo1.company = "나도회사";

	printf("게임 이름 : %s\n", gameInfo1.name);
	printf("발매 연도 : %d\n", gameInfo1.year);
	printf("게임 가격 : %d\n", gameInfo1.price);
	printf("제작 회사 : %s\n", gameInfo1.company);

	struct GameInfo gameInfo2 = {"너도게임", 2022, 100, "너도회사"};
	printf("게임 이름 : %s\n", gameInfo2.name);
	printf("발매 연도 : %d\n", gameInfo2.year);
	printf("게임 가격 : %d\n", gameInfo2.price);
	printf("제작 회사 : %s\n", gameInfo2.company);

	struct GameInfo gameArray[2] = {
		{"나도게임", 2022, 50, "나도회사"},
		{"너도게임", 202, 100, "너도회사"}
	};

	struct GameInfo* gamePtr; // 구조체 포인터 변수 선언
	gamePtr = &gameInfo1;
	printf("게임 이름 : %s\n", (*gamePtr).name);
	printf("발매 연도 : %d\n", (*gamePtr).year);
	printf("게임 가격 : %d\n", (*gamePtr).price);
	printf("제작 회사 : %s\n", (*gamePtr).company);

	gameInfo1.friendGame = &gameInfo2; // 다른 회사의 게임 정보를 담은  변수 주소 저장
	printf("게임 이름 : %s\n", gameInfo1.friendGame->name);
	printf("발매 연도 : %d\n", gameInfo1.friendGame->year);
	printf("게임 가격 : %d\n", gameInfo1.friendGame->price);
	printf("제작 회사 : %s\n", gameInfo1.friendGame->company);

	int i = 1;
	typedef int 정수; // int == 정수
	정수 정수변수 = 3; // int i = 3;

	typedef float 실수;
	실수 실수변수 = 3.23f; // float f = 3.23f;
	printf("정수변수 %d, 실수변수 %.2f\n", 정수변수, 실수변수);

	return 0;
}