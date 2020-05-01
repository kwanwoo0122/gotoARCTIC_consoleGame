#pragma once
#include <stdio.h>
#include <Windows.h>
#include "moveImage.h"
#include "timeCount.h"

char story1[30] = "story1.bmp";
char story2[30] = "story2.bmp";
char story3[30] = "story3.bmp";
char story4[30] = "story4.bmp";
char story5[30] = "story5.bmp";
char story6[30] = "story6.bmp";
char story7[30] = "story7.bmp";
char story8[30] = "story8.bmp";
char story9[30] = "story9.bmp";
char story10[30] = "story10.bmp";
char story11[30] = "story11.bmp";
char story12[30] = "story12.bmp";
char story13[30] = "story13.bmp";
char story14[30] = "story14.bmp";
char story15[30] = "story15.bmp";
char story16[30] = "story16.bmp";
char story17[30] = "story17.bmp";
char story18[30] = "story18.bmp";

int backG_imageX = 880;
int backG_imageY = 580;
int backG_imageZ = 2180;
int backG_imageR = 1260;
int checkB_imageX = 1800;
int checkB_imageY = 810;
int checkB_imageZ = 1932;
int checkB_imageR = 955;
int temp_saveCurTime = 0;

extern int WIDTH;
extern int HEIGHT;

#pragma comment(lib,"winmm.lib")
void startGame(int saveNum, int saveCurTime) // 게임을 시작하는 함수, 스토리를 보여주고 방으로 이동시킴
{
	temp_saveCurTime = saveCurTime;
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("storyMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	enableMouseInput();
	for (int i = 1; i <= 18; i++)
	{
		if (i == 1)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story1, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 2)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story2, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 3)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story3, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 4)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story4, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 5)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story5, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 6)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story6, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 7)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story7, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 8)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story8, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 9)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story9, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 10)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story10, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 11)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story11, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 12)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story12, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 13)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story13, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 14)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story14, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 15)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story15, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 16)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story16, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 17)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story17, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}
		else if (i == 18)
		{
			while (!(isMouseClicked() == 1))
			{
				pushImage(story18, WIDTH * 5.1, HEIGHT * 2, 3);
			}
		}

	}
	system("cls");
	PlaySound(NULL, 0, 0);
	Sleep(100);
	PlaySound(TEXT("mainRoomMusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	startTime(temp_saveCurTime);
	while (1)
		moveImage(saveNum, temp_saveCurTime);

}