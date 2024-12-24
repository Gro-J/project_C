#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 6������ �����
// clock �Լ� - ���� �ð��� ms ������ ��ȯ (time.h)
// CLOCKS_PER_SEC - 1000���� ����� ms �� s �� �ٲ���


void initData();
void printfFishes();
void decreaseWater(long ElapsedTime);
int checkFishAlive();


int* cursor;	//���׿� ���� �ְ��ϴ� ������ ����
int arrayFish[6];
int level;

int main_pointer_project(void)
{
	long startTime = 0;	// �ð��� ���� long �ڷ����� ���� ���
	long totalElapsedTime = 0;	// �� ��� �ð�
	long prevElapsedTime = 0;	// ���� ��� �ð�(�ֱٿ� ���� �� �ð� ����)

	int num;	// �� �� ���׿� ���� ������
	initData();

	cursor = arrayFish;	// ������ ������ �迭�� �־ cursor[0]...ó�� �����͸� �迭ó�� ��밡��

	startTime = clock();
	while (1)	// ���� �ݺ�
	{
		printfFishes();
		printf("�� �� ���׿� ���� �ٱ�? ");
		scanf_s("%d", &num);

		//�Է°� üũ 
		if (num < 1 || num>6)
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			continue;
		}

		// �� ��� �ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // ���� �ð� - ���� �ð�
		printf(" �� ��� �ð� : %ld ��\n", totalElapsedTime);

		// ���� ���� �� �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

		// ������ ���� ����
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� �� �ֱ�
		// 1.������ ���� 0�̸� ���� ���� ����
		if (cursor[num - 1] < 0)
		{
			printf("%d �� ������ �̹� �׾����ϴ�.\n\n", num);
		}
		// 2.������ ���� 100�� �Ѿ����� Ȯ��
		else if (cursor[num - 1] < 100)
		{
			printf("%d ���׿� ���� �ݴϴ�.\n\n", num);
			cursor[num - 1] = cursor[num - 1] + 1;
		}

		// �������� ���� ( 20�ʿ� �� �� ������)
		if (totalElapsedTime / 20 > level - 1)
		{
			level++;
			printf("%d �� ���� ��\n\n", level);
		}
		// ���� ������ 5
		if (level == 5)
		{
			printf("��緹�� ���! ��������. \n\n");
			exit(0);	// ��� ���α׷� ����
		}

		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			printf("��� ����Ⱑ ���� \n\n");
			exit(0);
		}
		else
		{
			printf("����Ⱑ ���� �������\n\n");
		}

		prevElapsedTime = totalElapsedTime;		// prevElapsedTime�� total�� �������־�� ���� �ݺ��� ���
	}

	





	return 0;
}

void initData()	// ���� ������ �ʱ�ȭ �Լ�
{
	level = 1;	// ���� 1 - 6
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100;	// ���� ���� 100
	}
}

void printfFishes()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d�� \n", 1, 2, 3, 4, 5, 6 );
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
		arrayFish[i] = arrayFish[i] - (level * 3 * (int)ElapsedTime);	// 1�ʿ� 3�� �پ��� ���� ��
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






















