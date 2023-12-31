#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
int arrayFish[6];
int* cursor; // 어항 배열에 접근할 포인터 변수 선언

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main2(void) {
	long startTime = 0; // 게임 시작 시간을 담을 변수 선언 및 초기화
	int num;
	long totalElapsedTime = 0; // 총 경과시간
	long prevElapsedTime = 0; // 직전에 물을 준 시간 (물을 준 간격)

	initData();
	startTime = clock();
	cursor = arrayFish; // 포인터 변수에 어항 배열의 시작 주소 넣기

	while (1) {
		printfFishes();
		printf("몇 번 어항에 물을 줄까요? (1-6) ");
		scanf_s("%d", &num);

		if (num < 1 || num > 6) {
			printf("\n입력값이 잘못됐습니다.\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 총 경과 시간 (초 단위로 표시)
		printf("총 경과 시간 : %ld초\n", totalElapsedTime);
		prevElapsedTime = totalElapsedTime - prevElapsedTime; // 직전에 물 준 시간 이후로 흐른 시간
		printf("최근 경과 시간 : %ld초\n", prevElapsedTime);

		decreaseWater(prevElapsedTime);
		if (cursor[num - 1] <= 0) {
			printf("%d번 어항의 물고기는 이미 죽었으므로 물을 주지 않습니다\n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d번 어항에 물을 줍니다\n\n", num);
			// 물을 주면 물 높이 + 1(cursor[num-1] = cursor[num -1] + 1)
			cursor[num - 1] += 1;
		}

		if (totalElapsedTime / 20 > level - 1) { // 레벨업 확인(20초마다 한 번씩 수행)
			level++;
			printf("***축하합니다. %d레벨에서 %d레벨로 올랐습니다. *** \n\n", level - 1, level);

			if (level == 5) {
				printf("\n\n축하합니다. 최고 레벨을 달성했습니다. 게임을 종료합니다. \n\n");
				exit(0);
			}
		}

		if (checkFishAlive() == 0) {
			printf("모든 물고기가 죽었습니다. ㅠㅠ \n\n");
			exit(0);
		}
		else {
			printf("물고기가 아직 살아있어요!\n\n");
		}

		prevElapsedTime = totalElapsedTime;
	}
	return 0;
}

void initData() {
	level = 1; // 레벨 초기화 (레벨 범위 1~5)
	for (int i = 0; i < 6; ++i) {
		arrayFish[i] = 100; // 어항 물 높이 초기화 (물 높이 범위 0~100)
	}
}

void printfFishes() { // 어항 물 높이 출력 함수 정의
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; ++i) {
		printf("  %3d ", arrayFish[i]); // 서식 지정자로 출력 결과 정렬
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) { // 어항의 물을 증발(감소)시키는 함수 정의
	for (int i = 0; i < 6; ++i) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime);

		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() { // 모든 물고기가 죽었는지 확인하는 함수
	for (int i = 0; i < 6; ++i) {
		if (arrayFish[i] > 0) {
			return 1; // 참(true)
		}
	}

	return 0;
}