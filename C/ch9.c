#include <stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price; 
	char* company;
};

int main(void) {
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

	return 0;
}