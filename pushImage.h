#pragma once
#include <stdio.h>
#include "ImageLayer.h"

void pushImage(char *imageName, double x, double y, double scale) { // 이미지 출력하는 함수
	Sleep(500);

	ImageLayer imageLayer = DEFAULT_IMAGE_LAYER;
	imageLayer.initialize(&imageLayer); //초기화

	Image images[2] = {

		{imageName, x, y, scale}, //{이미지 이름, 시작 x좌표, 시작 y좌표, 크기 배율(쓰지 않으면 기본값인 16이 들어감)} 
		//{"characterFront.bmp", 800, 92, 1} //문자열 앞에  L을 꼭 붙여줘야 한다.
		//{L"sample.bmp", 200, 200}
	}; //배열의 첫 원소가 가장 아래 그려진다.

	imageLayer.imageCount = 2; //images 배열의 크기보다 작거나 같아야 한다.
	imageLayer.images = images;

	imageLayer.renderAll(&imageLayer);
}