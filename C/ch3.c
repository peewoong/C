#include <stdio.h>

int main(void) {
	for (int i = 1; i <= 30; i++) {
		if (6 <= i && i <= 10) {
			if (i == 7) {
				printf("%d�� �л� ����\n", i);
				continue;
			}
			
			printf("%d�� �л� ��ǥ\n", i);
		}
	}

	return 0;
}