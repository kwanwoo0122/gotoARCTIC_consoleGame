#pragma once
#include <stdio.h>
#include <Windows.h>

COORD bufSize;

void fullscreenConsole() { // 콘솔창 화면 최대사이즈 설정 함수
	system("cls");

	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(hCon, CONSOLE_FULLSCREEN_MODE, NULL);

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hCon, &info); // 콘솔창의 정보를 얻어온다.

	

	//콘솔창의 최대 사이즈를 받아온다.
	bufSize.X = info.dwMaximumWindowSize.X;
	bufSize.Y = info.dwMaximumWindowSize.Y;

	int ret = 0;

	//콘솔창의 사이즈를 바꿔준다.
	ret = SetConsoleScreenBufferSize(hCon, bufSize);

	if (ret == 0) //실패하면 중지한다.
		abort();
}