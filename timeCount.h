#pragma once
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "console.h"

int currentTime;
int isTiming = 0; // 0 정지 1 재개
int pTime;
char timerShow[6];

void startTime(int time) // 시간을 매개변수로 전달하여 그 시간 만큼 타이머를 설정 및 시작하는 함수
{
	currentTime = time;
	isTiming = 1;
}

void stopTime() // 타이머를 멈추는 함수
{
	isTiming = 0;
}

void processTime() // 변경된 실제 시간을 감지하여 타이머의 시간을 줄이는 함수
{
	int cTime;
	cTime = (int)time(NULL) % 60;
	if (pTime != cTime) currentTime--;
	pTime = cTime;
	sprintf(timerShow, "%02d:%02d", currentTime / 60, currentTime % 60);
}