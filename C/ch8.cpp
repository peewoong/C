#include <stdio.h>

int arrayAnimal[4][5];
void initAnimalArray();

int main(void) {
	initAnimalArray();
	return 0;
}

void initAnimalArray() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 5; ++j) {
			arrayAnimal[i][j] = -1; // 카드 뒷면 설정
		}
	}
}