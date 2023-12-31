#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5];
char* strAnimal[10]; // ���� �̸� �迭
int checkAnimal[4][5]; // ī�� �޸�, �ո� Ȯ�� �迭 ����

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();

int main4(void) {
	int failCount = 0;
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();
	shuffleAnimal();

	while (1) {
		int select1 = 0;
		int select2 = 0;
		printAnimals();
		printQuestion();
		printf("\n������ ī�� 2���� ������. �� 12 4 -> ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) {
			continue;
		}

		// �Է¹��� ī�� ��ȣ�� x, y ��ǥ�� ��ȯ
		int firstSelectX = conv_pos_x(select1);
		int firstSelectY = conv_pos_y(select1);
		int secondSelectX = conv_pos_x(select2);
		int secondSelectY = conv_pos_y(select2);

		if ((checkAnimal[firstSelectX][firstSelectY] == 0
			&& checkAnimal[secondSelectX][secondSelectY] == 0
			&& (arrayAnimal[firstSelectX][firstSelectY] == arrayAnimal[secondSelectX][secondSelectY]))) {
			// �� ī�尡 ���� �����̰� �޸��� ���
			printf("\n\n����! %s �߰�\n\n", strAnimal[arrayAnimal[firstSelectX][firstSelectY]]);
			checkAnimal[firstSelectX][firstSelectY] = 1;
			checkAnimal[secondSelectX][secondSelectY] = 1;
		}
		else { // �� ī�尡 �ٸ� �����̰ų� �ո��� ���
			printf("\n\n��! ���� �ٸ� ���� ī��ų� �̹� ������ ī���Դϴ�.\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelectX][firstSelectY]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelectX][secondSelectY]]);
			printf("\n");
			failCount++;
		}

		if (foundAllAnimals() == 1) {
			printf("\n\n�����մϴ�. ��� ������ ã�ҽ��ϴ�.\n");
			printf("�� %d�� �����Ͽ����ϴ�.\n", failCount);
			break;
		}
	}

	
	return 0;
}

void initAnimalArray() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			arrayAnimal[i][j] = -1; // ī�� �޸� ����
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "������";
	strAnimal[1] = "�ϸ�";
	strAnimal[2] = "������";
	strAnimal[3] = "�����";
	strAnimal[4] = "����";
	strAnimal[5] = "�ڳ���";
	strAnimal[6] = "�⸰";
	strAnimal[7] = "��Ÿ";
	strAnimal[8] = "Ÿ��";
	strAnimal[9] = "ȣ����";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 2; ++j) {
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);
			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20;
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}

	return 0;
}

int conv_pos_x(int x) {
	return x / 5;
}

int conv_pos_y(int y) {
	return y % 5;
}

void printAnimals() {
	printf("\n ���� ��ġ�� �����ݴϴ�.\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n");
}

void printQuestion() {
	printf("\n����\n\n");
	int seq = 0;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (checkAnimal[i][j] == 1) { // ī�尡  ���̸�
				printf("%8s", strAnimal[arrayAnimal[i][j]]); // ���� �̸� ���
			}
			else {
				printf("%8d", seq); // ī�� ��ȣ ���
			}
			seq++; // ���� ī��� �Ѿ��
		}
		printf("\n");
	}
}

int foundAllAnimals() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (checkAnimal[i][j] == 0) {
				return 0; // ������ ���� ī�尡 ����
			}
		}
	}

	return 1; // ��� ī�� ������
}