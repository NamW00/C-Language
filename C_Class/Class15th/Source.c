#include <stdio.h>
#include <time.h>

void UpdateHPBar(int life)
{
	for (int i = 0; i < life; i++) {
		printf("��");
	}
}

void UpdateUI()
{
	printf("\n��ǻ�Ͱ� ������ �ִ� �� : ");
}

int main()
{
#pragma region rand �Լ�
	// 0 ~ 32767 ������ ���� ���� �����ϰ� ��ȯ�ϴ� �Լ��Դϴ�.

	//seed ������ ���� �ð��� ������ �ʴ� seed���� ����ؼ� ��ȭ�Ǳ� ������ 
	//������ ������ ������ ������ ���� ���� �� �ֽ��ϴ�.
	/*srand(time(NULL));

	int seed = 0;



	for (int i = 0; i < 5; i++)
	{
	seed = rand();

	printf("seed�� �� : %d\n", seed % 10 + 1);

	}*/


#pragma endregion

#pragma region ���ٿ� game
	//scanf_s(); �Է�
	//ũ�ٸ� ��ǻ�Ͱ� ������ �ִ� ������ Ů�ϴ�.
	//�۴ٸ� ��ǻ�Ͱ� ������ �ִ� ������ �۽��ϴ�.
	//Life�� 0���� �۰ų� ���ٸ� ��������.
	//�������� Victory
	//Life 0�̸� Defeat
	//���� ��ü�� While������ �������� break
	srand(time(NULL));
	int life = 5;
	// 1. ��ǻ�� ������ 0~50������ ���� ���� �־��ݴϴ�.
	int computer = rand() % 50 + 1;
	// 2. ��ǻ�Ͱ� ������ �ִ� ���� ���߱� ���� ���� ����
	int answer = 0;


	while (1)
	{
		UpdateHPBar(life); // HPBar�� ����ϴ� �Լ�
		UpdateUI(); // �Է��� ���� �� �ִ� �ؽ�Ʈ�� �Է��ϴ� �Լ�
		// ��ǻ�Ͱ� ������ �ִ� ���� �Է��մϴ�.
		scanf_s("%d", &answer);

		system("cls");

		if (answer == computer)
		{
			printf("\n V i c t o r y");
			break;
		}
		else if (answer < computer)
		{
			life--;
			printf("��ǻ�Ͱ� ������ �ִ� ������ �۽��ϴ�.");
		}
		else if (answer > computer)
		{
			life--;
			printf("��ǻ�Ͱ� ������ �ִ� ������ Ů�ϴ�.");
		}

		if (life <= 0)
		{
			printf("\nDefeat");
			break;
		}
	}




	//cls�� ����� �Է��� ����ŭ ��Ʈ�� �þ�� �ڵ�
	/*	for (int i = 0; i < life; i++)
	{
	printf("��");
	}
	printf("\n");
	system("cls");
	}*/


#pragma endregion



	return 0;
}