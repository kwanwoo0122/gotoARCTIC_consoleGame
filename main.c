#include <stdio.h>
#include "console.h"
#include "displayStart.h"

int WIDTH;
int HEIGHT;

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define UP 72
#define SPACE 32

int main() //메인함수, 기본설정이후 시작화면을 띄워줌
{
	backgroundSetting();
	displayStart();

	getchar();
}