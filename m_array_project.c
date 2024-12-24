#include<stdio.h>
#include<time.h>



int arrayAnimal[4][5];	// ��ü ī��
int checkAnimal[4][5];	// ������ ���� Ȯ�� (0�� 1�� �̷���� �迭)
void initAnimalarray();
void initAnimalname();
void shuffleAnimal();	// ���� ȭ�鿡 ����ī�带 ��� ��ġ����
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

	int failCount = 0;	// ���� Ƚ��


	while (1)
	{
		int select1 = 0;	// ����ڰ� ������ ó�� ��
		int select2 = 0;	// ����ڰ� ������ �ι�° ��

		printAnimals();	// ���� ��ġ ���
		printQuest();	//���� ���

		printf("ī�带 �����ϼ���.\n\n");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)	// ���� ��ġ�� ī�帣 �����ϸ� ��ȿ
		{
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������� Ȯ��

		// ���� ��ǥ�� (x,y)�� ��ȯ
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);


		// ���� ������ ���
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0			// ī�尡 �������� �ʾҴ���
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)

			&& (arrayAnimal[firstSelect_x][firstSelect_y]			// ���� ��������
			== arrayAnimal[secondSelect_x][secondSelect_y]))
		{
			printf("\n\n ���� : %s �߰� \n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;		// �����̴ϱ� ������ ���·� �ٲ���
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		// �ٸ� ������ ���
		else
		{
			printf("�����Դϴ�.(�̹� ������ ī�带 �������� �� �ֽ��ϴ�)\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;

		}

		// ��� ������ ã�Ҵ��� ���� 1 : �� 0 : ����

		if (foundAllAnimals() == 1)
		{
			printf("��� ������ �� ã�ҽ��ϴ�. ���� ���� \n\n\n");
			printf("���� Ƚ�� : %d ", failCount);
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

void shuffleAnimal()	// �迭 20ĭ���� ��ĭ 2���� ã�� ���ʴ�� ���� �̸� �ֱ�
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


int getEmptyPosition()	// ��ǥ���� �� ���� ã��
{
	while (1)
	{
		int randPos = rand() % 20;	// 0-19 ������ ����
		// 19 -> (3,4)�� ��ȯ ����� ��
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
	printf("\n\n(����)\n");
	int seq = 0;

	for (int i= 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//���� -> �����̸� ǥ��
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}

			//���� -> �޸�(����)
			else
			{
				printf("%8d", seq);	
			}
			seq++;	// seq++�� ���� ��ȣ�� ���
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
			if (checkAnimal[i][j] == 0)		// ���� �ȵ������� �ϳ��� ������
			{
				return 0;
			}
		
		}
	}
	return 1;	// ��� �� ã��
}