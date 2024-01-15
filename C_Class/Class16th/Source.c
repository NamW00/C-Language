#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BUFFER_SIZE 10000

void LoadFile(const char* fileName) {
	//"data.txt" 파일을 열어주고 r (읽기) 모드로 설정합니다.
	FILE* file = fopen(fileName, "r");

	// 상대 경로
	// 절대 경로

	char buffer[BUFFER_SIZE] = { 0, };

	fread(buffer, 1, BUFFER_SIZE, file); // 전체 파일을 읽어주는 함수

	printf("%s", buffer);

	fclose(file);
}

int main()
{
#pragma region 파일 쓰기
	////"data.txt" 파일을 생성하고 w(쓰기) 모드로 설정합니다.
	//FILE * file = fopen("data.txt","w");

	//fputs("level 10", file);

	//// 파일을 닫아줍니다.
	//fclose(file);

#pragma endregion
#pragma region 파일 이어쓰기
	////"data.txt" 파일을 생성하고 a (이어쓰기) 모드로 설정합니다.
	//FILE * file = fopen("data.txt","a");

	//fputs("\nMP 100", file);

	//// 파일을 닫아줍니다.
	//fclose(file);
#pragma endregion
#pragma region 파일 읽기
	////"data.txt" 파일을 열어주고 r (읽기) 모드로 설정합니다.
	//FILE * file = fopen("Image/Pika.txt","r");

	//// 상대 경로
	//// 절대 경로

	//char buffer[BUFFER_SIZE] = { 0,};

	//fread(buffer, 1, BUFFER_SIZE, file); // 전체 파일을 읽어주는 함수

	//printf("%s", buffer);

	//fclose(file);

	//함수로 txt명만 변경하면 실행될 수 있게끔
	LoadFile("Image/Pika.txt");
	LoadFile("Image/Meta.txt");


#pragma endregion





	return 0;
}


