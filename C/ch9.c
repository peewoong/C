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
	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "�ѱ� ����";
	game1.year = 2022;

	GAME_INFO game2;
	game2.name = "�ѱ� ����2";
	game2.year = 2023;

	struct GameInformation game3;
	game3.name = "�ѱ� ����3";

	printf("���� �̸� : %s\n", game1.name);
	printf("�߸� ���� : %d\n", game1.year);
	printf("���� �̸� : %s\n", game2.name);
	printf("�߸� ���� : %d\n", game2.year);

	return 0;
}

int main9(void) {
	struct GameInfo gameInfo1;
	gameInfo1.name = "��������";
	gameInfo1.year = 2022;
	gameInfo1.price = 50;
	gameInfo1.company = "����ȸ��";

	printf("���� �̸� : %s\n", gameInfo1.name);
	printf("�߸� ���� : %d\n", gameInfo1.year);
	printf("���� ���� : %d\n", gameInfo1.price);
	printf("���� ȸ�� : %s\n", gameInfo1.company);

	struct GameInfo gameInfo2 = {"�ʵ�����", 2022, 100, "�ʵ�ȸ��"};
	printf("���� �̸� : %s\n", gameInfo2.name);
	printf("�߸� ���� : %d\n", gameInfo2.year);
	printf("���� ���� : %d\n", gameInfo2.price);
	printf("���� ȸ�� : %s\n", gameInfo2.company);

	struct GameInfo gameArray[2] = {
		{"��������", 2022, 50, "����ȸ��"},
		{"�ʵ�����", 202, 100, "�ʵ�ȸ��"}
	};

	struct GameInfo* gamePtr; // ����ü ������ ���� ����
	gamePtr = &gameInfo1;
	printf("���� �̸� : %s\n", (*gamePtr).name);
	printf("�߸� ���� : %d\n", (*gamePtr).year);
	printf("���� ���� : %d\n", (*gamePtr).price);
	printf("���� ȸ�� : %s\n", (*gamePtr).company);

	gameInfo1.friendGame = &gameInfo2; // �ٸ� ȸ���� ���� ������ ����  ���� �ּ� ����
	printf("���� �̸� : %s\n", gameInfo1.friendGame->name);
	printf("�߸� ���� : %d\n", gameInfo1.friendGame->year);
	printf("���� ���� : %d\n", gameInfo1.friendGame->price);
	printf("���� ȸ�� : %s\n", gameInfo1.friendGame->company);

	int i = 1;
	typedef int ����; // int == ����
	���� �������� = 3; // int i = 3;

	typedef float �Ǽ�;
	�Ǽ� �Ǽ����� = 3.23f; // float f = 3.23f;
	printf("�������� %d, �Ǽ����� %.2f\n", ��������, �Ǽ�����);

	return 0;
}