#include <stdio.h>

int main(void) {
	char name[256];
	printf("�̸��� ������?\n");
	scanf_s("%s", name, (unsigned  int)sizeof(name));
	printf("%s\n", name);

	return 0;
}