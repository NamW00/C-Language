#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>	 //키이동을 할 수 있도록 도와주는 헤더파일 key
#include <windows.h> //좌표이동을 할 수 있도록 도와주는 헤더파일 Coordinate 
// -> COORD(좌표설정)에 필요한 헤더파일

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void GotoXY(int x, int y)
{
	// x, y 좌표 설정
	COORD position = { x, y };

	// 커서 이동 함수
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	int i = 2;
	int	j = 5;
	GotoXY(i, j);
	printf("☆");


	char key = 0;
	while (1)
	{
		if (_kbhit()) //키보드 입력확인 (true/false)
		{

			key = _getch();	// key 입력을 받아주는 함수

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

			//if조건문에서 조건 두개 &&(and), ||(or)

			GotoXY(i, j);
			printf("☆");
		}
	}


	//while (1)
	//{
	//	if (_kbhit()) //키보드 입력확인 (true/false)
	//	{
	//		key = _getch();	// key 입력을 받아주는 함수
	//		
	//		// printf("입력 값 : %c\n", key);

	//		if(key == -32)
	//		{
	//			key = _getch();
	//			// _getch(); 처음 입력받으면 0이 아닌 다른 수가 저장되어 있기 때문에 -32라는 수가 출력된다.
	//			// 그래서 한번더 입력받아줌으로서 본래의 값이 입력되도록 한다.
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
			//	default: printf("key 변수의 값 : %d\n",key);
			//		break;
	//		}
	//	}
	//}



	return 0;

}