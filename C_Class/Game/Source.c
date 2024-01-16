#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define WIDTH 11
#define HEIGHT 11

char maze[WIDTH][HEIGHT];

void CreateMaze()
{
	// 0 : 빈 공간 (" ")
	// 1 : 벽 (□)
	// 2 : 탈출구 (◎)

	strcpy(maze[0], "1011111111");
	strcpy(maze[1], "1000111111");
	strcpy(maze[2], "1110100011");
	strcpy(maze[3], "1110001001");
	strcpy(maze[4], "1000101111");
	strcpy(maze[5], "1010100011");
	strcpy(maze[6], "1011111011");
	strcpy(maze[7], "1000001111");
	strcpy(maze[8], "1110100111");
	strcpy(maze[9], "1000110001");
	strcpy(maze[10], "1111111102");
}

void Render()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
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
	CreateMaze();
	Render();
	return 0;
}