#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>	 //Ű�̵��� �� �� �ֵ��� �����ִ� ������� key
#include <windows.h> //��ǥ�̵��� �� �� �ֵ��� �����ִ� ������� Coordinate 
// -> COORD(��ǥ����)�� �ʿ��� �������

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void GotoXY(int x, int y)
{
	// x, y ��ǥ ����
	COORD position = { x, y };

	// Ŀ�� �̵� �Լ�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	int i = 2;
	int	j = 5;
	GotoXY(i, j);
	printf("��");


	char key = 0;
	while (1)
	{
		if (_kbhit()) //Ű���� �Է�Ȯ�� (true/false)
		{

			key = _getch();	// key �Է��� �޾��ִ� �Լ�

			system("cls");

			if (key == -32)
			{
				key = _getch();
			}

			switch (key)
			{
			case UP:
				if (j > 0) { j--; }
				break;
			case LEFT:
				if (i > 0) { i -= 2; }
				break;
			case RIGHT: i += 2;
				break;
			case DOWN: j++;
				break;
			}

			//if���ǹ����� ���� �ΰ� &&(and), ||(or)

			GotoXY(i, j);
			printf("��");
		}
	}


	//while (1)
	//{
	//	if (_kbhit()) //Ű���� �Է�Ȯ�� (true/false)
	//	{
	//		key = _getch();	// key �Է��� �޾��ִ� �Լ�
	//		
	//		// printf("�Է� �� : %c\n", key);

	//		if(key == -32)
	//		{
	//			key = _getch();
	//			// _getch(); ó�� �Է¹����� 0�� �ƴ� �ٸ� ���� ����Ǿ� �ֱ� ������ -32��� ���� ��µȴ�.
	//			// �׷��� �ѹ��� �Է¹޾������μ� ������ ���� �Էµǵ��� �Ѵ�.
	//		}

			//switch (key)
			//{
			//	case UP : printf("UP\n");
			//		break;
			//	case LEFT : printf("LEFT\n");
			//		break;
			//	case RIGHT : printf("RIGHT\n");
			//		break;
			//	case DOWN : printf("DOWN\n");
			//		break;
			//	default: printf("key ������ �� : %d\n",key);
			//		break;
	//		}
	//	}
	//}



	return 0;

}