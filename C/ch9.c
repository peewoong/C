#include <stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price; 
	char* company;
};

int main(void) {
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

	return 0;
}