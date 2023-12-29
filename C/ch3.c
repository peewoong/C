#include <stdio.h>

int main(void) {
	for (int i = 1; i <= 30; i++) {
		if (6 <= i && i <= 10) {
			if (i == 7) {
				printf("%d번 학생 조퇴\n", i);
				continue;
			}
			
			printf("%d번 학생 발표\n", i);
		}
	}

	return 0;
}