#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
int arrayFish[6];
int* cursor; // ���� �迭�� ������ ������ ���� ����

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main2(void) {
	long startTime = 0; // ���� ���� �ð��� ���� ���� ���� �� �ʱ�ȭ
	int num;
	long totalElapsedTime = 0; // �� ����ð�
	long prevElapsedTime = 0; // ������ ���� �� �ð� (���� �� ����)

	initData();
	startTime = clock();
	cursor = arrayFish; // ������ ������ ���� �迭�� ���� �ּ� �ֱ�

	while (1) {
		printfFishes();
		printf("�� �� ���׿� ���� �ٱ��? (1-6) ");
		scanf_s("%d", &num);

		if (num < 1 || num > 6) {
			printf("\n�Է°��� �߸��ƽ��ϴ�.\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // �� ��� �ð� (�� ������ ǥ��)
		printf("�� ��� �ð� : %ld��\n", totalElapsedTime);
		prevElapsedTime = totalElapsedTime - prevElapsedTime; // ������ �� �� �ð� ���ķ� �帥 �ð�
		printf("�ֱ� ��� �ð� : %ld��\n", prevElapsedTime);

		decreaseWater(prevElapsedTime);
		if (cursor[num - 1] <= 0) {
			printf("%d�� ������ ������ �̹� �׾����Ƿ� ���� ���� �ʽ��ϴ�\n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d�� ���׿� ���� �ݴϴ�\n\n", num);
			// ���� �ָ� �� ���� + 1(cursor[num-1] = cursor[num -1] + 1)
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 20 > level - 1) { // ������ Ȯ��(20�ʸ��� �� ���� ����)
			level++;
			printf("***�����մϴ�. %d�������� %d������ �ö����ϴ�. *** \n\n", level - 1, level);

			if (level == 5) {
				printf("\n\n�����մϴ�. �ְ� ������ �޼��߽��ϴ�. ������ �����մϴ�. \n\n");
				exit(0);
			}
		}

		if (checkFishAlive() == 0) {
			printf("��� ����Ⱑ �׾����ϴ�. �Ф� \n\n");
			exit(0);
		}
		else {
			printf("����Ⱑ ���� ����־��!\n\n");
		}

		prevElapsedTime = totalElapsedTime;
	}
	return 0;
}

void initData() {
	level = 1; // ���� �ʱ�ȭ (���� ���� 1~5)
	for (int i = 0; i < 6; ++i) {
		arrayFish[i] = 100; // ���� �� ���� �ʱ�ȭ (�� ���� ���� 0~100)
	}
}

void printfFishes() { // ���� �� ���� ��� �Լ� ����
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; ++i) {
		printf("  %3d ", arrayFish[i]); // ���� �����ڷ� ��� ��� ����
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) { // ������ ���� ����(����)��Ű�� �Լ� ����
	for (int i = 0; i < 6; ++i) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime);

		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() { // ��� ����Ⱑ �׾����� Ȯ���ϴ� �Լ�
	for (int i = 0; i < 6; ++i) {
		if (arrayFish[i] > 0) {
			return 1; // ��(true)
		}
	}

	return 0;
}