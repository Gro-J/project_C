#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 6마리의 물고기
// clock 함수 - 현재 시간을 ms 단위로 반환 (time.h)
// CLOCKS_PER_SEC - 1000으로 나누어서 ms 를 s 로 바꿔줌


void initData();
void printfFishes();
void decreaseWater(long ElapsedTime);
int checkFishAlive();


int* cursor;	//어항에 물을 주게하는 포인터 변수
int arrayFish[6];
int level;

int main_pointer_project(void)
{
	long startTime = 0;	// 시간은 보통 long 자료형을 많이 사용
	long totalElapsedTime = 0;	// 총 경과 시간
	long prevElapsedTime = 0;	// 직전 경과 시간(최근에 물을 준 시간 간격)

	int num;	// 몇 번 어항에 물을 넣을지
	initData();

	cursor = arrayFish;	// 포인터 변수에 배열을 넣어서 cursor[0]...처럼 포인터를 배열처럼 사용가능

	startTime = clock();
	while (1)	// 무한 반복
	{
		printfFishes();
		printf("몇 번 어항에 물을 줄까? ");
		scanf_s("%d", &num);

		//입력값 체크 
		if (num < 1 || num>6)
		{
			printf("잘못 입력하셨습니다.\n");
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 현재 시간 - 시작 시간
		printf(" 총 경과 시간 : %ld 초\n", totalElapsedTime);

		// 직전 물을 준 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		// 어항의 물을 감소
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물 주기
		// 1.어항의 물이 0이면 물을 주지 않음
		if (cursor[num - 1] < 0)
		{
			printf("%d 번 물고기는 이미 죽었습니다.\n\n", num);
		}
		// 2.어항의 물이 100이 넘었는지 확인
		else if (cursor[num - 1] < 100)
		{
			printf("%d 어항에 물을 줍니다.\n\n", num);
			cursor[num - 1] = cursor[num - 1] + 1;
		}

		// 레벨업의 유무 ( 20초에 한 번 레벨업)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("%d 로 레벨 업\n\n", level);
		}
		// 최종 레벨은 5
		if (level == 5)
		{
			printf("모든레벨 통과! 게임종료. \n\n");
			exit(0);	// 모든 프로그램 종료
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			printf("모든 물고기가 죽음 \n\n");
			exit(0);
		}
		else
		{
			printf("물고기가 아직 살아있음\n\n");
		}

		prevElapsedTime = totalElapsedTime;		// prevElapsedTime을 total로 저장해주어야 다음 반복때 사용
	}

	





	return 0;
}

void initData()	// 게임 데이터 초기화 함수
{
	level = 1;	// 레벨 1 - 6
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100;	// 어항 높이 100
	}
}

void printfFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6 );
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n\n");
}

void decreaseWater(long ElapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = arrayFish[i] - (level * 3 * (int)ElapsedTime);	// 1초에 3씩 줄어드는 물의 양
		if (arrayFish[i] < 0)
		{
			arrayFish[i] == 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1;
	}
	return 0;
}






















