#include<stdio.h>
#include<time.h>	
#include<stdlib.h>

int main_find_treatment(void)
{
	srand(time(NULL)); //���� �ʱ�ȭ ��������

	printf("\n\n === �߸��� ã�� ���� === \n\n");

	int answer;	//����� �Է°�
	int treatment = rand() % 4;  //�߸��� ����(0-3)

	int cntShowBottle = 0; // �� ���ӿ� ������ ���� ����
	int prevcntShowBottle = 0; // �� ���ӿ� ������ �� ����
	// ���� �ٸ� ������ ���� �����ֱ� ���ؼ� 

	// 3���� ��ȸ
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 }; // 4���� ��
		do {
			cntShowBottle = rand() % 2 + 2; // 2,3���� ���� �����ְ� �ϱ����ؼ� %2 +2�� ���� ���
		} while (cntShowBottle == prevcntShowBottle);

		int isincluded = 0; // �����ִ� �� �߿� �߸��� ���� ����
		printf(" > %d ��° �õ� : ", i);

		//������ �� ���� ����
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4;

			//���� ���õ��� ���� ���� �� ����ó��
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					isincluded = 1; // �߸��� ����
				}
			}
			// �̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ����
			else
			{
				j--; //j++�Ѱ� ��ȿȭ
			}
		}

		//����ڿ��� ǥ��
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
				printf("%d ", k + 1); // K+1�� ���� 0->1�� ����� ���� ������ ���ؼ�

		}
		printf(" ������ �Ӹ��� �ٸ��ϴ�\n\n");

		if (isincluded == 1)
		{
			printf("���� �Ӹ��� �ڶ�\n");
		}
		else
		{
			printf("���� �Ӹ��� �ڶ��� ����\n\n");
		}

		printf("��� �Ϸ��� ���� Ű�� �Է�....\n");
		getchar();	//getchar() �Լ��� �Ű�� �Է��� �� ���� ����ϴ� �뵵

	}

	printf("�߸����� ����ϱ��?\n");
	scanf_s("%d", &answer);


	if (answer == treatment+1)	//treatment �� 0-3 �̹Ƿ� ������ ���߱� ���ؼ� + 1
	{
		printf("����");
	}
	else
	{
		printf("�� Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�.", treatment + 1);
	}
	return 0;
}