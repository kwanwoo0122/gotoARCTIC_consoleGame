#pragma once
#include <stdio.h>
#include "console.h"
#include "pushImage.h"
#include "MouseInput.h"

extern int WIDTH;
extern int HEIGHT;
extern int isEnding;

void pushSavefile(int room, int curTime) // 세이브파일 저장하는 함수
{
	FILE* sf1, * sf2;
	sf1 = fopen("세이브파일1.txt", "w");
	fprintf(sf1, "%d", room);
	fclose(sf1);
	sf2 = fopen("세이브파일2.txt", "w");
	fprintf(sf2, "%d", curTime);
	fclose(sf2);
	enableMouseInput();
	if (isEnding != 1)
	{
		while (!(isMouseClicked() == 1))
		{
			pushImage("finishSave.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
		}
	}
}