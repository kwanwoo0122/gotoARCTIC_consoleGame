#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include "loadSavefile.h"

extern int WIDTH;
extern int HEIGHT;
int saveRoom = 0;
int saveCurTime = 0;

#pragma comment(lib,"winmm.lib")
void continueGame() // 이어하기 함수
{
	PlaySound(TEXT("saveFileMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	loadSavefile();
	Sleep(100);
	startGame(saveRoom, saveCurTime);
}