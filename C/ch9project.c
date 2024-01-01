#include <stdio.h>
#include <time.h>
#include <stdio.h>

typedef struct {
	char* name;
	char* character;
	int age;
	int level;
} CAT;

CAT cats[5]; // ū ���ڿ� �ִ� ����� ���
int collection[5] = { 0,0,0,0,0 };

void initCats();
void printCat(int selected);
int checkCollection();

int main(void) {
	srand(time(NULL));
	initCats();

	while (1) {
		printf("�αٵα�! ��� ������� ���簡 �ɱ��? \n���͸� ���� Ȯ���ϼ���!");
		getchar();
		int selected = rand() % 5;
		printCat(selected);

		collection[selected] = 1;
		int collectAll = checkCollection();

		if (collectAll == 1) {
			break; // ����� 5������ ��� ������ ���� �ݺ��� Ż��
		}
	}

	return 0;
}

void initCats() {
	cats[0].name = "A";
	cats[0].age = 5;
	cats[0].character = "�¼���";
	cats[0].level = 1;

	cats[1].name = "B";
	cats[1].age = 3;
	cats[1].character = "��ĥ��";
	cats[1].level = 2;

	cats[2].name = "C";
	cats[2].age = 7;
	cats[2].character = "���� ����";
	cats[2].level = 3;

	cats[3].name = "D";
	cats[3].age = 2;
	cats[3].character = "�ò�����";
	cats[3].level = 4;

	cats[4].name = "E";
	cats[4].age = 1;
	cats[4].character = "�� �����";
	cats[4].level = 5;
}

void printCat(int selected) {
	printf("������� ������ ����մϴ�\n");
	printf("�̸� : %s\n", cats[selected].name);
	printf("���� : %d\n", cats[selected].age);
	printf("Ư¡ : %s\n", cats[selected].character);
	printf("���� : ");
	for (int i = 0; i < cats[selected].level; ++i) {
		printf("%s", "��");
	}
	printf("\n\n");
}

int checkCollection() {
	int collectAll = 1;
	printf("������ ����� ����Դϴ�. \n\n");
	for (int i = 0; i < 5; ++i) {
		if (collection[i] == 0) {
			printf("%10s", "(�� ����)");
			collectAll = 0;
		}
		else {
			printf("%10s", cats[i].name);
		}
	}
	printf("\n\n");

	if (collectAll) {
		printf("\n�����մϴ�. 5������ ����̸� ��� ��Ҿ��. ������ Ű���ּ���\n");
	}

	return collectAll;
}