#include <stdio.h>

int main(void) {
	char name[256];
	printf("이름이 뭐예요?\n");
	scanf_s("%s", name, (unsigned  int)sizeof(name)); // 형변환
	printf("%s\n", name);

	return 0;
}