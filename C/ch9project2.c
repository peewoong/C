#include <stdio.h>

typedef struct book {
	int id; // ��ȣ(id)
	char* title; // ����
	int available; // 0 : ���� ��, 1 : ���� ����
} BOOK;

BOOK book[4];
void initBook();
void printBook();

int main99(void) {
	int bookNum;
	initBook();
	
	while (1) {
		printBook();
		printf("�뿩�� å ��ȣ�� �Է����ּ��� (���� : -1) : ");
		scanf_s("%d", &bookNum);

		if (bookNum == -1) {
			printf("���α׷��� �����մϴ�\n");
			break;
		}
		if (bookNum < -1 || bookNum > 4) {
			printf("�߸��� �Է��Դϴ�.\n");
			continue;
		}

		bookNum--;
		if (book[bookNum].available == 0) {
			printf("%s �ݳ��� �Ϸ�Ǿ����ϴ�.\n", book[bookNum].title);
			book[bookNum].available = 1;
		}
		else {
			printf("%s ������ �Ϸ�Ǿ����ϴ�.\n", book[bookNum].title);
			book[bookNum].available = 0;
		}
	}

	return 0;
}

void initBook() {
	book[0].id = 1;
	book[0].title = "C �Թ���";
	book[0].available = 0;

	book[1].id = 2;
	book[1].title = "���̽� �⺻��";
	book[1].available = 1;

	book[2].id = 3;
	book[2].title = "�ڹ� �⺻��";
	book[2].available = 0;

	book[3].id = 4;
	book[3].title = "���̽� �߱���";
	book[3].available = 1;
}

void printBook() {
	for (int i = 0; i < 4; ++i) {
		printf("%d.", book[i].id);
		printf("%-16s", book[i].title);
		if (book[i].available == 1) {
			printf("[���� ����]\n");
		}
		else {
			printf("[���� ��]\n");
		}
	}
}