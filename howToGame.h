#pragma once
#include <stdio.h>
#include <Windows.h>
#include "startGame.h"
#include "displayStart.h"

extern int WIDTH;
extern int HEIGHT;

#pragma comment(lib,"winmm.lib")
void howToGame() // 게임 방법 설명 이미지를 띄우는 함수
{
	PlaySound(TEXT("saveFileMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	enableMouseInput();
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage("howToGame1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage("howToGame2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
	}
	system("cls");
	PlaySound(NULL, 0, 0);
	Sleep(10);
}