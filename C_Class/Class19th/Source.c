#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>	
#include <windows.h>

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


#define WIDTH 11
#define HEIGHT 11

char maze[WIDTH][HEIGHT];

typedef struct Player
{
	int x;
	int y;
	const char* shape;

}Player;

void CreateMaze()
{
	// 0 : 빈 공간 (" ") -> but 특수 문자가 2byte이므로 2번 띄어줘야한다.
	// 1 : 벽 (■)
	// 2 : 탈출구 (◎)

	strcpy(maze[0], "1111111111");
	strcpy(maze[1], "1000100001");
	strcpy(maze[2], "1110001101");
	strcpy(maze[3], "1110101001");
	strcpy(maze[4], "1000101111");
	strcpy(maze[5], "1010100001");
	strcpy(maze[6], "1110111101");
	strcpy(maze[7], "1000001001");
	strcpy(maze[8], "1011101111");
	strcpy(maze[9], "1000100021");
	strcpy(maze[10], "1111111111");
}

void Render()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++) {
			switch (maze[i][j])
			{
			case '0':
				printf("  ");
				break;
			case '1':
				printf("■");
				break;
			case '2':
				printf("◎");
				break;
			default:
				break;
			}
			/*if (maze[i][j] == '0')
			{
				printf("  ");
			}
			else if (maze[i][j] == '1')
			{
				printf("■");
			}
			else if  (maze[i][j] == '2')
			{
				printf("◎");
			}*/
			//	printf("%c", maze[i][j]);		//이 때 maze는 숫자가 아닌 문자열이므로 %c를 써야함
		}
		printf("\n");
	}

}

void Keyboard(char map[WIDTH][HEIGHT], Player* player)
{
	char key = 0;

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
		case UP: if (maze[player->y - 1][player->x / 2] != '1') { player->y--; }
			   break;
		case LEFT: if (maze[player->y][player->x / 2 - 1] != '1') { player->x -= 2; }
				 break;
		case RIGHT: if (maze[player->y][player->x / 2 + 1] != '1') { player->x += 2; }
				  break;
		case DOWN: if (maze[player->y + 1][player->x / 2] != '1') { player->y++; }
				 break;
		}
	}
}

//typedef struct Student
//{
//	char name[10];
//}Student;

int	main()
{
#pragma region strcpy
	//Student student;

	//student.name;

	//// student.name = "KIM";  주소값에 주소를 넣는 것 자체가 말이 안되는 것

	////strcpy 매개변수는 두개가 들어감
	//// 첫번째 매개변수 : 복사받을 문자 배열을 넣어줍니다.
	//// 두번째 매개변수 : 복사시킬 문자열을 넣어줍니다.
	//strcpy(student.name, "KIM");

	//printf("student.name의 값 : %s\n", student.name);

	//strcpy(student.name, "NAM");

	//printf("student.name의 값 : %s\n", student.name);

#pragma endregion
	Player player = {2,1,"☆"};

	// 1. 맵 데이터를 생성합니다.
	CreateMaze();

	while (1)
	{
	// 2. 맵 데이터에 있는 정보를 토대로 출력합니다.
	Render();

	Keyboard(maze, &player);	//map[][]가 하나의 포인터라고 해당된다. maze가 Keyboard 함수의 char 

	GotoXY(player.x, player.y);
	printf("%s", player.shape);

	Sleep(100);
	system("cls");
	}

	return 0;
}