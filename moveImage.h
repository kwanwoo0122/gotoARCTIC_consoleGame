#pragma once
#include <stdio.h>
#include <math.h>
#include "pushImage.h"
#include "MouseInput.h"
#include "displayEnding.h"
#include "timeCount.h"

//마우스 입력을 2개의 변수로 나누어 받았습니다. 하나는 캐릭터 이동을 위해 입력받은 마우스값을 좀 보정했고, 
//checkB_가 붙은 건 캐릭터의 벽 막기를 위해 보정하지 않은 마우스값을 받았습니다.

extern int WIDTH;
extern int HEIGHT;
extern int backG_imageX;
extern int backG_imageY;
extern int backG_imageZ;
extern int backG_imageR;
extern int checkB_imageX;
extern int checkB_imageY;
extern int checkB_imageZ;
extern int checkB_imageR;

int flag = 0;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int cnt = 0;
int cnt1 = 0;
int cnt2 = 0;
int clearEnding = 0;
int roomNum = 0;

double nowX = 1800; //이미지 현재 x좌표
double nowY = 810;  //이미지 현재 y좌표
double checkB_nowX = 0, checkB_nowY = 0;

char mainRoom1[30] = "mainRoom1.bmp";
char mainRoom2[30] = "mainRoom2.bmp";
char mainRoom3[30] = "mainRoom3.bmp";
char imageFront[30] = "characterFront.bmp";
char imageBack[30] = "characterBack.bmp";
char imageRight[30] = "characterRight.bmp";
char imageLeft[30] = "characterLeft.bmp";

extern char timerShow[6]; //현재 남은 시간 문자열
extern int isTiming; // 시간을 재고 있는가
extern int currentTime; //현재 남은 시간
/*
moveImage 함수 설명:
마우스 포인터의 좌표값을 받아 그 위치로 캐릭터를 이동시키고,
중간에 다시 마우스 입력이 있다면 다시 입력된 위치로 캐릭터를 이동시키는 함수입니다.
캐릭터가 벽을 나가려고 하면, 그 행동을 막습니다.
또한, 제한시간인 5분을 왼쪽 위에 보여줍니다.
시계 앞으로 가면 세이브를 할 건지 결정하도록 하였습니다.
가운데에 있는 실험기구가 놓여 있는 탁자 옆의 금고 앞에 서면, 단서를 얻을 수 있도록 하였습니다.
첫번째와 두번째 방에서는 단서를 보고 있을 때 단서를 통해 알게 된 비밀번호를 입력하면 다음 스테이지로 넘어가도록 하였고,
뒤로가기(back)를 위해 b또는 B버튼을 누르면 단서를 내려놓도록 하였습니다.
사물에서 발견할 수 있는 모양이나 색 등을 단서를 통해 표현하여 비밀번호를 알 수 있도록 하였습니다.
선생님도 한번 해보시면 좋을 것 같습니다. 
하지만 매우 어려우니 비밀번호의 이유를 듣고 싶으시다면 1404김관우, 1407김진우에게 와 주시면 친절하게 설명해드리겠습니다.
마지막 방에서, 캐릭터가 문 앞에 서면, 문을 열건지 결정하도록 하였습니다.
문을 열면 엔딩을 보여주는 함수를 호출합니다.
*/


void moveImage(int saveNum, int saveCurTime) {
	roomNum = saveNum;
	ImageLayer layer = DEFAULT_IMAGE_LAYER;
	layer.initialize(&layer);
	layer.imageCount = 2;

	Image images[2] = {
	   {mainRoom1, WIDTH * 5.1, HEIGHT * 2, 3} ,
	   {imageFront, nowX, nowY, 1}
	};
	layer.images = images;
	if (roomNum == 1)
		layer.images->fileName = mainRoom1;
	else if (roomNum == 2)
		layer.images->fileName = mainRoom2;
	else if (roomNum == 3)
		layer.images->fileName = mainRoom3;
	layer.renderAll(&layer);
	enableMouseInput();
	double speed_penguin = 5;

	int penguinDestX = nowX, penguinDestY = nowY;
	int checkB_DestX = 0, checkB_DestY = 0;
	double x_move = 0, y_move = 0;
	double checkB_x_move = 0, checkB_y_move = 0;
	while (1) {
		if (isTiming) processTime();
		gotoxy(0, 0);
		printf("%s", timerShow);
		if (currentTime == 0)
		{
			stopTime();
			flag3 = 1;
			break;
		}
		if (hasInput() && isMouseClicked() == 2) {

			COORD pos = getMousePosition();

			penguinDestX = pos.X * 0.9;
			penguinDestY = pos.Y * 0.8;
			checkB_DestX = pos.X;
			checkB_DestY = pos.Y;

			if (penguinDestX == layer.images[1].x && penguinDestY == layer.images[1].y) break;
			nowX = layer.images[1].x;
			nowY = layer.images[1].y;
			checkB_nowX = layer.images[1].x;
			checkB_nowY = layer.images[1].y;

			double dis = sqrt(pow(pos.X * 0.9 - layer.images[1].x, 2) + pow(pos.Y * 0.8 - layer.images[1].y, 2));
			double checkB_dis = sqrt(pow(pos.X - layer.images[1].x, 2) + pow(pos.Y - layer.images[1].y, 2));

			x_move = (double)(pos.X * 0.9 - layer.images[1].x) / dis * speed_penguin;
			y_move = (double)(pos.Y * 0.8 - layer.images[1].y) / dis * speed_penguin;
			checkB_x_move = (double)(pos.X - layer.images[1].x) / checkB_dis * speed_penguin;
			checkB_y_move = (double)(pos.Y - layer.images[1].y) / checkB_dis * speed_penguin;
		}
		while (penguinDestX != layer.images[1].x || penguinDestY != layer.images[1].y)
		{
			if (isTiming) processTime();
			gotoxy(0, 0);
			printf("%s", timerShow);
			if (currentTime == 0)
			{
				stopTime();
				flag3 = 1;
				break;
			}
			if (1630 <= checkB_imageX + 50 && checkB_imageX + 50 <= 1820 && 580 <= checkB_imageY + 50 && checkB_imageY + 50 <= 600 && roomNum == 3)
			{
				if (flag == 0 && cnt == 0)
				{
					flag = 1;
					break;
				}
			}
			else cnt = 0;
			
			if (1855 <= checkB_imageX + 50 && checkB_imageX + 50 <= 2045 && 580 <= checkB_imageY + 50 && checkB_imageY + 50 <= 600)
			{
				if (flag1 == 0 && cnt1 == 0)
				{
					flag1 = 1;
					break;
				}
			}
			else cnt1 = 0;
			if (1288 <= checkB_imageX && checkB_imageX <= 1436 && 844 <= checkB_imageY && checkB_imageY <= 900 && cnt == 0)
			{
				if (flag2 == 0 && cnt2 == 0)
				{
					flag2 = 1;
					break;
				}
			}
			else cnt2 = 0;

			if (hasInput() && isMouseClicked() == 2) {
				COORD pos = getMousePosition();

				penguinDestX = pos.X * 0.9;
				penguinDestY = pos.Y * 0.8;
				checkB_DestX = pos.X;
				checkB_DestY = pos.Y;

				if (penguinDestX == layer.images[1].x && penguinDestY == layer.images[1].y) break;


				nowX = layer.images[1].x;
				nowY = layer.images[1].y;

				checkB_nowX = layer.images[1].x;
				checkB_nowY = layer.images[1].y;

				double dis = sqrt(pow(pos.X * 0.9 - layer.images[1].x, 2) + pow(pos.Y * 0.8 - layer.images[1].y, 2));
				double checkB_dis = sqrt(pow(pos.X - layer.images[1].x, 2) + pow(pos.Y - layer.images[1].y, 2));

				x_move = (double)(pos.X * 0.9 - layer.images[1].x) / dis * speed_penguin;
				y_move = (double)(pos.Y * 0.8 - layer.images[1].y) / dis * speed_penguin;
				checkB_x_move = (double)(pos.X - layer.images[1].x) / checkB_dis * speed_penguin;
				checkB_y_move = (double)(pos.Y - layer.images[1].y) / checkB_dis * speed_penguin;
			}
			if (abs(penguinDestX - layer.images[1].x) > abs(penguinDestY - layer.images[1].y))
			{
				if ((penguinDestX - layer.images[1].x) > 0)
				{
					layer.images[1].fileName = imageLeft;
					layer.renderAll(&layer);
				}
				else
				{
					layer.images[1].fileName = imageRight;
					layer.renderAll(&layer);
				}
			}
			else if (abs(penguinDestX - layer.images[1].x) < abs(penguinDestY - layer.images[1].y))
			{
				if ((penguinDestY - layer.images[1].y) > 0)
				{
					layer.images[1].fileName = imageFront;
					layer.renderAll(&layer);
				}
				else
				{
					layer.images[1].fileName = imageBack;
					layer.renderAll(&layer);
				}
			}

			if (!(backG_imageX < (int)(checkB_nowX + checkB_x_move) && (int)(checkB_nowX + checkB_x_move ) + 132 < backG_imageZ
				&& backG_imageY < (int)(checkB_nowY + checkB_y_move) && (int)(checkB_nowY + checkB_y_move) + 145 < backG_imageR))
			{
				if (backG_imageX >= (int)(checkB_nowX + checkB_x_move)) layer.images[1].x++;
				if (backG_imageZ <= (int)(checkB_nowX + checkB_x_move) + 132) layer.images[1].x--;
				if (backG_imageY >= (int)(checkB_nowY + checkB_y_move)) layer.images[1].y = backG_imageY++;
				if (backG_imageR <= (int)(checkB_nowY + checkB_y_move) + 145) layer.images[1].y = backG_imageR--;

				penguinDestX = layer.images[1].x;
				penguinDestY = layer.images[1].y;
				checkB_DestX = layer.images[1].x;
				checkB_DestY = layer.images[1].y;

				nowX = layer.images[1].x;
				nowY = layer.images[1].y;
				checkB_nowX = layer.images[1].x;
				checkB_nowY = layer.images[1].y;
				break;
			}
			nowX += x_move;
			nowY += y_move;
			checkB_nowX += checkB_x_move;
			checkB_nowY += checkB_y_move;
			layer.images[1].x = (int)nowX;
			layer.images[1].y = (int)nowY;
			checkB_imageX = (int)checkB_nowX;
			checkB_imageY = (int)checkB_nowY;
			checkB_imageZ = checkB_imageX + 132;
			checkB_imageR = checkB_imageY + 145;
			layer.renderAll(&layer);

			double nextX = nowX + x_move, nextY = nowY + y_move;
			if (
				((nowX <= penguinDestX && penguinDestX < nextX) || (nowX >= penguinDestX && penguinDestX > nextX))
				|| ((nowY <= penguinDestY && penguinDestY < nextY) || (nowY >= penguinDestY && penguinDestY > nextY))
				) {
				nowX = penguinDestX;
				nowY = penguinDestY;
				checkB_nowX = checkB_DestX;
				checkB_nowY = checkB_DestY;

				layer.images[1].x = (int)nowX;
				layer.images[1].y = (int)nowY;
				checkB_imageX = (int)checkB_nowX;
				checkB_imageY = (int)checkB_nowY;
				checkB_imageZ = checkB_imageX + 132;
				checkB_imageR = checkB_imageY + 145;
				layer.renderAll(&layer);
				break;
			}
		}
		if ((flag == 1 && cnt == 0) || (flag1 == 1 && cnt1 == 0) || (flag2 == 1 && cnt2==0) || flag3 == 1)
				break;
	}
	if (flag3 == 1)
	{
		Sleep(50);
		clearEnding = 0;
		system("cls");
		displayEnding();
		return;
	}
	if (flag == 1) //문
	{
		Sleep(30);
		pushImage("door1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
		Sleep(20);
		pushImage("door2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
		int input = 0;
		while (input != 'Y' || input != 'y' || input != 'N' || input != 'n')
		{
			input = _getch();
			if (input == 'Y' || input == 'y')
			{
			R_SOLVE:
				Sleep(20);
				pushImage("door3.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
				int a, b, c, d;
				a = _getch();
				b = _getch();
				c = _getch();
				d = _getch();
				if (a == '1' && b == '0' && c == '0' && d == '3')
				{
					clearEnding = 1;
					displayEnding();
					break;
				}
				else if (a == 'B' || a == 'b')
				{
					flag = 0;
					cnt = 1;
					Sleep(20);
					moveImage(3, currentTime);
				}
				else
				{
					Sleep(20);
					pushImage("door4.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
					int solveTry = 0;
					while (solveTry != 'Y' || solveTry != 'y' || solveTry != 'N' || solveTry == 'n')
					{
						solveTry = _getch();
						if (solveTry == 'Y' || solveTry == 'y')
						{
							goto R_SOLVE;
						}
						else if (solveTry == 'N' || solveTry == 'n')
						{
							flag = 0;
							cnt = 1;
							Sleep(20);
							moveImage(3, currentTime);
						}
					}
				}
				goto R_SOLVE;
			}
			else if (input == 'N' || input == 'n')
			{
				flag = 0;
				cnt = 1;
				Sleep(20);
				moveImage(3, currentTime);
			}
		}
	}
	if (flag1 == 1)//시계
	{
		Sleep(30);
		if(roomNum == 1)
			pushImage("clock1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
		else if(roomNum == 2)
			pushImage("clock2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
		else if (roomNum == 3)
			pushImage("clock3.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
		int input = 0;
		while (input != 'Y' || input != 'y' || input != 'N' || input != 'n')
		{
			input = _getch();
			if (input == 'Y' || input == 'y')
			{
				pushSavefile(roomNum, currentTime);
				flag1 = 0;
				cnt1 = 1;
				Sleep(20);
				moveImage(roomNum, currentTime);
			}
			else if (input == 'N' || input == 'n')
			{
				flag1 = 0;
				cnt1 = 1;
				Sleep(20);
				moveImage(roomNum, currentTime);
			}
		}
	}
	if (flag2 == 1) //퀘스트
	{
		int tryQuest = 0;
	R_RETRY:
		tryQuest = 0;
		Sleep(30);
		while (1)
		{
			if(roomNum == 1)
				pushImage("solve1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
			else if(roomNum == 2)
				pushImage("solve2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
			else if (roomNum == 3)
				pushImage("solve3.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
			if (_kbhit && roomNum == 3)
			{
				tryQuest = 1;
				break;
			}
			if (_kbhit && roomNum != 3)
			{
				tryQuest = 1;
				if (roomNum == 1)
					pushImage("solve1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
				else if (roomNum == 2)
					pushImage("solve2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
				else if (roomNum == 3)
					pushImage("solve3.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
				break;
			}
		}
		if (tryQuest == 1 && roomNum == 3)
		{
			int a;
		R_WRONG:
			a = _getch();
			if (a == 'B' || a == 'b')
			{
				flag2 = 0;
				cnt2 = 1;
				moveImage(roomNum, currentTime);
			}
			else goto R_WRONG;
		}
		if (tryQuest == 1)
		{
			Sleep(20);
			int a, b, c, d;
			a = _getch();
			if (a == 'B' || a == 'b')
			{
				flag2 = 0;
				cnt2 = 1;
				moveImage(roomNum, currentTime);
			}
			b = _getch();
			c = _getch();
			d = _getch();
			if (roomNum == 1)
			{
				if (a == '3' && b == '1' && c == '2' && d == '2')
				{
					roomNum++;
					layer.images->fileName = mainRoom2;
					flag2 = 0;
					cnt2 = 1;
					moveImage(roomNum, currentTime);
				}
				else
				{
					Sleep(20);
					if (roomNum == 1)
						pushImage("wrongSolve1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
					else if (roomNum == 2)
						pushImage("wrongSolve2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
					Sleep(500);
					tryQuest = 0;
					goto R_RETRY;
				}
			}
			else if (roomNum == 2)
			{
				if (a == '6' && b == '8' && c == '2' && d == '2')
				{
					roomNum++;
					layer.images->fileName = mainRoom3;
					flag2 = 0;
					cnt2 = 1;
					moveImage(roomNum, currentTime);
				}
				else
				{
					Sleep(20);
					if (roomNum == 1)
						pushImage("wrongSolve1.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
					else if (roomNum == 2)
						pushImage("wrongSolve2.bmp", WIDTH * 5.1, HEIGHT * 2, 3);
					Sleep(500);
					tryQuest = 0;
					goto R_RETRY;
				}
			}
		}
		flag2 = 0;
		cnt2 = 1;
		moveImage(roomNum, currentTime);
	}

}