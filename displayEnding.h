#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include "pushImage.h"
#include "pushSavefile.h"

char ending[30] = "ending.bmp";
char GameFail[30] = "GameFail.bmp";
char openDoor[30] = "openDoor.bmp";

extern int WIDTH;
extern int HEIGHT;
extern int flag;
extern int flag1;
extern int clearEnding;

int isEnding = 0;

#pragma comment(lib,"winmm.lib")

void displayEnding() // 결과에 따라 엔딩 보여주는 함수
{
	if (clearEnding == 1)
	{
		Sleep(20);
		pushImage(openDoor, WIDTH * 5.1, HEIGHT * 2, 3);
		Sleep(1500);
	}
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("endingMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	isEnding = 1;
	pushSavefile(1, 300);
	while (!(isMouseClicked() == 1))
	{
		if(clearEnding == 1)
			pushImage(ending, WIDTH * 5.1, HEIGHT * 2, 3);
		else if(clearEnding == 0)
			pushImage(GameFail, WIDTH * 5.1, HEIGHT * 2, 3);
	}
	Sleep(100);
	if (clearEnding == 1)
		pushImage("reGame.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
	if (clearEnding == 0)
		pushImage("reGameFail.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
	int input = 0;
	while (input != 'Y' || input != 'y' || input != 'N' || input != 'n')
	{
		input = _getch();
		if (input == 'Y' || input == 'y')
		{
			PlaySound(NULL, 0, 0);
			flag = 0;
			flag1 = 0;
			clearEnding = 0;
			main();
		}
		else if (input == 'N' || input == 'n')
		{	
			exit(0);
			break;
		}
	}
}