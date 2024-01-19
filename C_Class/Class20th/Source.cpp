#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>	
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

// 버퍼의 크기
int width = 100;
int height = 60;

// 버퍼를 생성합니다.
HANDLE screen[2];	//값을 안넣었기 때문에 BSS메모리에 들어간다.
//screen[0] front buffer
//screen[1] back buffer

//HANDLE 인덱스에 접근해서 버퍼를 교체시키는 변수
int screenIndex = 0;


void GotoXY(int x, int y)
{
	// x, y 좌표 설정
	COORD position = { x, y };

	// 커서 이동 함수
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// 버퍼를 초기화하는 함수
void ScreenInit()
{
	CONSOLE_CURSOR_INFO cursor;

	// 버퍼의 가로 사이즈, 세로 사이즈
	COORD size = { width, height };

	// left, top, right, bottom
	SMALL_RECT rect{ 0,0,width - 1,height - 1 };

	// 화면 2개를 생성합니다.
	// front buffer 생성
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	// 버퍼의 사이즈를 설정하는 함수
	SetConsoleScreenBufferSize(screen[0], size);

	SetConsoleWindowInfo(screen[0], TRUE, &rect);

	// back buffer 생성
	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	// 버퍼의 사이즈를 설정하는 함수
	SetConsoleScreenBufferSize(screen[1], size);

	SetConsoleWindowInfo(screen[1], TRUE, &rect);

	// 커서의 활성화 여부
	// false : 거짓 (0) 
	// true : 참 (1)

	cursor.bVisible = false;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);

}

// 버퍼를 교체하는 함수
void FlipScreen()
{
	// 버퍼는 하나만 활성화 시킬 수 있습니다.
	SetConsoleActiveScreenBuffer(screen[screenIndex]);


	screenIndex = !screenIndex;	// not 연산자로 0, 1 값 반전하면서 버퍼를 교체시켜줘야한다.
}

// 교체된 버퍼를 지워주는 함수
void ClearScreen()
{
	COORD coord = { 0,0 };
	DWORD dw;

	FillConsoleOutputCharacter
	(
		screen[screenIndex],
		' ',
		width * height,
		coord,
		&dw
	);
}

// 버퍼를 해제하는 함수
void ReleaseScreen()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

// 더블 버퍼링을 사용해서 출력하는 함수
void PrintfScreen(int x, int y, const char* string)
{
	COORD cursorPosition = { x,y };

	DWORD dw;

	SetConsoleCursorPosition(screen[screenIndex], cursorPosition);

	WriteFile
	(
		screen[screenIndex],
		string,
		strlen(string),
		&dw,
		NULL
	);
}



int	main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	// 1. 버퍼를 초기화합니다. Init -> 초기화하다 약자
	ScreenInit();

	// 색상을 설정하는 함수
	// 0 = 검정
	// 1 = 블루
	// 2 = 초록
	// 3 = 옥색
	// 4 = 빨강
	// 5 = 자주
	// 6 = 노랑
	// 7 = 흰색
	// 8 = 회색
	// enum을 가지고도 색상 변경 가능




	while (1)
	{
		PrintfScreen(5, 5, "Hello");

		// 2. 버퍼를 교체합니다.
		FlipScreen();

		// 3. 교체된 버퍼의 내용을 삭제합니다.
		ClearScreen();
	}

	// 4. 게임이 종료되었을 때 버퍼를 해제합니다.
	ReleaseScreen();


	return 0;
}
// ctrl + alt + L 누르면 오른쪽에 Solution Explore가 뜬다.