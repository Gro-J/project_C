#include<stdio.h>
#include<time.h>	
#include<stdlib.h>

int main_find_treatment(void)
{
	srand(time(NULL)); //난수 초기화 잊지말기

	printf("\n\n === 발모제 찾기 게임 === \n\n");

	int answer;	//사용자 입력값
	int treatment = rand() % 4;  //발모제 선택(0-3)

	int cntShowBottle = 0; // 한 게임에 보여줄 병의 갯수
	int prevcntShowBottle = 0; // 앞 게임에 보여준 병 갯수
	// 서로 다른 갯수의 병을 보여주기 위해서 

	// 3번의 기회
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 }; // 4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 2,3개의 병을 보여주게 하기위해서 %2 +2의 수식 사용
		} while (cntShowBottle == prevcntShowBottle);

		int isincluded = 0; // 보여주는 병 중에 발모제 포함 여부
		printf(" > %d 번째 시도 : ", i);

		//보여줄 병 종류 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4;

			//아직 선택되지 않은 병일 때 선택처리
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isincluded = 1; // 발모제 포함
				}
			}
			// 이미 선택된 병이면, 중복이므로 다시 선택
			else
			{
				j--; //j++한것 무효화
			}
		}

		//사용자에게 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
				printf("%d ", k + 1); // K+1은 단지 0->1로 만들기 위함 순서를 위해서

		}
		printf(" 물약을 머리에 바릅니다\n\n");

		if (isincluded == 1)
		{
			printf("성공 머리가 자람\n");
		}
		else
		{
			printf("실패 머리가 자라지 않음\n\n");
		}

		printf("계속 하려면 다음 키를 입력....\n");
		getchar();	//getchar() 함수는 어떤키를 입력할 때 까지 대기하는 용도

	}

	printf("발모제는 몇번일까요?\n");
	scanf_s("%d", &answer);


	if (answer == treatment+1)	//treatment 는 0-3 이므로 순서를 맞추기 위해서 + 1
	{
		printf("정답");
	}
	else
	{
		printf("땡 틀렸습니다. 정답은 %d 입니다.", treatment + 1);
	}
	return 0;
}