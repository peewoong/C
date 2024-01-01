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
		printf("파일 열기 실패\n");
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
	char line[MAX]; // char line[10000]; // 파일에서 읽어 오는 문자열 저장 배열 선언
	FILE* file = fopen("E:\\programming\\C\\test1.txt", "rb");

	if (file == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}

	while (fgets(line, MAX, file) != NULL) { // fgets() 함수로 파일 읽기
		printf("%s", line); // 읽어 올 문자열 출력
	}

	fclose(file); // 파일 닫기
	return 0;
}