#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define WIDTH 11
#define HEIGHT 11

char maze[WIDTH][HEIGHT];

void CreateMaze()
{
	// 0 : �� ���� (" ")
	// 1 : �� (��)
	// 2 : Ż�ⱸ (��)

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

	//// student.name = "KIM";  �ּҰ��� �ּҸ� �ִ� �� ��ü�� ���� �ȵǴ� ��

	////strcpy �Ű������� �ΰ��� ��
	//// ù��° �Ű����� : ������� ���� �迭�� �־��ݴϴ�.
	//// �ι�° �Ű����� : �����ų ���ڿ��� �־��ݴϴ�.
	//strcpy(student.name, "KIM");

	//printf("student.name�� �� : %s\n", student.name);

	//strcpy(student.name, "NAM");

	//printf("student.name�� �� : %s\n", student.name);

#pragma endregion
	CreateMaze();
	Render();
	return 0;
}