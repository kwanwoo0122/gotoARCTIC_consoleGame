/*
민승현의 이미지 레이어를 사용하였습니다.
*/

#pragma once
#include <Windows.h>

typedef struct {
	char* fileName;
	int x, y;
	double scale;
}Image;

typedef struct _ImageLayer {
	//멤버 변수
	Image* images;
	int imageCount;
	UINT transparentColor;

	HWND _windowHandle;
	HDC _consoleDC;

	//함수
	void (*initialize)(struct _ImageLayer*);//초기화 함수
	void (*renderAll)(struct _ImageLayer*);
	void (*fadeIn)(struct _ImageLayer*, void(*applyToBackDC)(HDC));
	void (*fadeOut)(struct _ImageLayer*, void(*applyToBackDC)(HDC));
}ImageLayer;