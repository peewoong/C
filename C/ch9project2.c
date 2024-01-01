#include <stdio.h>

typedef struct book {
	int id; // 번호(id)
	char* title; // 제목
	int available; // 0 : 대출 중, 1 : 대출 가능
} BOOK;

BOOK book[4];
void initBook();
void printBook();

int main99(void) {
	int bookNum;
	initBook();
	
	while (1) {
		printBook();
		printf("대여할 책 번호를 입력해주세요 (종료 : -1) : ");
		scanf_s("%d", &bookNum);

		if (bookNum == -1) {
			printf("프로그램을 종료합니다\n");
			break;
		}
		if (bookNum < -1 || bookNum > 4) {
			printf("잘못된 입력입니다.\n");
			continue;
		}

		bookNum--;
		if (book[bookNum].available == 0) {
			printf("%s 반납이 완료되었습니다.\n", book[bookNum].title);
			book[bookNum].available = 1;
		}
		else {
			printf("%s 대출이 완료되었습니다.\n", book[bookNum].title);
			book[bookNum].available = 0;
		}
	}

	return 0;
}

void initBook() {
	book[0].id = 1;
	book[0].title = "C 입문편";
	book[0].available = 0;

	book[1].id = 2;
	book[1].title = "파이썬 기본편";
	book[1].available = 1;

	book[2].id = 3;
	book[2].title = "자바 기본편";
	book[2].available = 0;

	book[3].id = 4;
	book[3].title = "파이썬 중급편";
	book[3].available = 1;
}

void printBook() {
	for (int i = 0; i < 4; ++i) {
		printf("%d.", book[i].id);
		printf("%-16s", book[i].title);
		if (book[i].available == 1) {
			printf("[대출 가능]\n");
		}
		else {
			printf("[대출 중]\n");
		}
	}
}