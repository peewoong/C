#include <stdio.h>

void swap(int a, int b);
void swap_addr(int * a, int * b);
void changeArray(int* ptr);

//int main(void) {
//	int arr2[3] = { 10, 20, 30 };
//	changeArray(arr2);
//	for (int i = 0; i < 3; ++i) {
//		printf("%d\n", arr2[i]);
//	}
//
//	return 0;
//}

//int main(void) {
//	int a = 10;
//	int b = 20;
//	printf("a�� �ּ� : %p\n", &a);
//	printf("b�� �ּ� : %p\n", &b);
//
//	printf("swap_addr() �Լ� ȣ�� �� => a : %d, b : %d\n", a, b);
//	swap_addr(&a, &b);
//	printf("swap_addr() �Լ� ȣ�� �� => a : %d, b : %d\n", a, b);
//
//	return 0;
//}

void swap(int a, int b) {
	printf("swap() �Լ� �ȿ��� a�� �ּ� : %p\n", &a);
	printf("swap() �Լ� �ȿ��� b�� �ּ� : %p\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("swap() �Լ� �� => a : %d, b : %d\n", a, b);
}

void swap_addr(int * a, int * b){
	printf("swap_addr() �Լ� �ȿ��� a�� �ּ� : %p\n", a);
	printf("swap_addr() �Լ� �ȿ��� b�� �ּ� : %p\n", b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap_addr() �Լ� �� => a : %d, b : %d\n", *a, *b);
}

void changeArray(int* ptr) {
	ptr[2] = 50;
}

int pointer(void) {
	int arr[3] = { 5,10,15 };
	for (int i = 0; i < 3; i++) {
		printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
	}

	int* ptr = arr;
	for (int i = 0; i < 3; i++) {
		printf("������ ���� ptr[%d]�� �� : %d\n", i, ptr[i]);
	}

	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;

	printf("arr ��ü�� ���� �ּ��� ���� �� : %d\n", *arr);
	printf("arr[0]�� ���� �� : %d\n", *&arr[0]);

	return 0;
}