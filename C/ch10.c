#define _CRT_SECURE_NO_WARNINGS
#define MAX 10000
#include <stdio.h>

int main(void) {
	char str1[MAX];
	char str2[MAX];
	int num[6] = { 0, 0, 0, 0, 0, 0 };
	int bonus = 0;

	FILE * file = fopen("E:\\programming\\C\\test2.txt", "rb");
	
	if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}

	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);
	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);
	
	fclose(file);
	return 0;
}

int main11(void) {
	char line[MAX]; // char line[10000]; // ���Ͽ��� �о� ���� ���ڿ� ���� �迭 ����
	FILE* file = fopen("E:\\programming\\C\\test1.txt", "rb");

	if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}

	while (fgets(line, MAX, file) != NULL) { // fgets() �Լ��� ���� �б�
		printf("%s", line); // �о� �� ���ڿ� ���
	}

	fclose(file); // ���� �ݱ�
	return 0;
}