#include <stdio.h>
#include <stdlib.h>

enum Unit
{
	//�������� ���� ���� �������� ������ ���� ���� �ִ� ����
	//0�̶�� ������ �����˴ϴ�.
	SKELETON,	//0
	SLIME,		//1
	GOBLIN		//2

	// ���������� �߰��� �ִ� ���� �����ϰ� �Ǹ� �״����� �ִ�
	// ���� +1�� �˴ϴ�.
};

void CreateUnit(enum Unit unit)
{

	switch (unit)
	{
	case SKELETON: printf("Create Skeleton\n");
		break;
	case SLIME: printf("Create Slime\n");
		break;
	case GOBLIN: printf("Create Goblin\n");
		break;
	default:
		break;
	}
}


int main()
{
#pragma region ������ �迭

	//const char* string[3];
	//// 8 byte 8 8
	//// [  ] [  ] [  ]
	////
	//// "Blue" "Black" "Green"

	//
	//string[0] = "Blue";
	//string[1] = "Black";
	//string[2] = "Green";

	//for (int i = 0; i < 3; i++)
	//{
	//	//printf("string[%d] : %p\n", i, string[i]);
	//	//printf("string[%d] : %c\n", i, *string[i]);
	//	printf("string[%d] : %s\n", i, string[i]);
	//}


#pragma endregion

#pragma region ������
	CreateUnit(SKELETON);
	CreateUnit(SLIME);
	CreateUnit(GOBLIN);



	/*enum Unit unit;

	unit = SKELETON;

	switch (unit)
	{
	case SKELETON: printf("Create Skeleton");
		break;
	case SLIME : printf("Create Slime");
		break;
	case GOBLIN: printf("Create Goblin");
		break;
	default:
		break;
	}*/

#pragma endregion

#pragma region ��� ������
	// �̹� ������ �޸� ������ ����Ű�� �������Դϴ�.

	//int * ptr = malloc(sizeof(4)); //malloc�� ����ڰ� ���� �����Ҽ��ִ� ���� ������

	//*ptr = 999;

	//printf("*ptr�� �� : %d\n", *ptr);
	//
	//free(ptr); 

	//printf("*ptr�� �� : %d\n", *ptr);
	//
	//ptr = NULL;
	//
	//if (ptr == NULL)
	//{
	//	ptr = malloc(sizeof(4));

	//}

	//*ptr = 235;
	//
	//printf("*ptr�� �� : %d\n", *ptr);

	//free(ptr);


#pragma endregion



	return 0;
}
