#include<stdio.h>
#include<time.h>



int arrayAnimal[4][5];	// 전체 카드
int checkAnimal[4][5];	// 뒤집힘 여부 확인 (0과 1로 이루어진 배열)
void initAnimalarray();
void initAnimalname();
void shuffleAnimal();	// 게임 화면에 동물카드를 어떻게 배치할지
int getEmptyPosition();
void printAnimals();
void printQuest();
int foundAllAnimals();




char* strAnimal[10];


int main_m_array_project(void)
{
	srand(time(NULL));

	initAnimalarray();
	initAnimalname();

	shuffleAnimal();

	int failCount = 0;	// 실패 횟수


	while (1)
	{
		int select1 = 0;	// 사용자가 선택한 처음 수
		int select2 = 0;	// 사용자가 선택한 두번째 수

		printAnimals();	// 동물 위치 출력
		printQuest();	//문제 출력

		printf("카드를 선택하세요.\n\n");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)	// 같은 위치의 카드르 선택하면 무효
		{
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어보고 확인

		// 정수 좌표를 (x,y)로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);


		// 같은 동물인 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0			// 카드가 뒤집히지 않았는지
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&& (arrayAnimal[firstSelect_x][firstSelect_y]			// 같은 동물인지
			== arrayAnimal[secondSelect_x][secondSelect_y]))
		{
			printf("\n\n 정답 : %s 발견 \n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;		// 정답이니까 뒤집힌 상태로 바꿔줌
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		// 다른 동물인 경우
		else
		{
			printf("오답입니다.(이미 뒤집힌 카드를 선택했을 수 있습니다)\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;

		}

		// 모든 동물을 찾았는지 여부 1 : 참 0 : 거짓

		if (foundAllAnimals() == 1)
		{
			printf("모든 동물을 다 찾았습니다. 게임 종료 \n\n\n");
			printf("오답 횟수 : %d ", failCount);
			break;
		}

		
	}







	return 0;
}

void initAnimalarray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalname()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";

	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal()	// 배열 20칸에서 빈칸 2개를 찾아 차례대로 동물 이름 넣기
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}


int getEmptyPosition()	// 좌표에서 빈 공간 찾기
{
	while (1)
	{
		int randPos = rand() % 20;	// 0-19 까지의 랜덤
		// 19 -> (3,4)로 변환 해줘야 함
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
}


//0  1  2  3  4
//5  6  7  8  9 
//10 11 12 13 14
//15 16 17 18 19
int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}


void printAnimals()
{
	for (int i= 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n===================================\n\n");
}

void printQuest()
{
	printf("\n\n(문제)\n");
	int seq = 0;

	for (int i= 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//정답 -> 동물이름 표시
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}

			//오답 -> 뒷면(숫자)
			else
			{
				printf("%8d", seq);	
			}
			seq++;	// seq++을 통해 번호를 출력
		}
		printf("\n\n");
		
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)		// 아직 안뒤집힌게 하나라도 있으면
			{
				return 0;
			}
		
		}
	}
	return 1;	// 모두 다 찾음
}