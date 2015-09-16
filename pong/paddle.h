#pragma once
#include <iostream>
#include "sfwdraw.h"
#include "paddle.h"
#include <ctime>


float yacc1 = 0;	  // acceleration
float yvel1 = 0;     // velocity
float yvel3 = 0;
float speed1 = 250;

float xpos1 = 25;
float ypos1 = 250;
float xpos2 = 25;
float ypos2 = 350;

float xpos3 = 775;
float ypos3 = 250;
float xpos4 = 775;
float ypos4 = 350;

void paddle1()
{

	if (sfw::getKey('w')) yvel1 = -speed1 * sfw::getDeltaTime();
	if (sfw::getKey('s')) yvel1 = speed1 * sfw::getDeltaTime();


	ypos1 += yvel1;
	ypos2 += yvel1;


	if (ypos2  > 592)
	{
		yvel1 = 0;

	}
	if (ypos1 < 8)
	{
		yvel1 = 0;
	}

	//stephen with the hook up
	sfw::drawLine(xpos1, ypos1, xpos2, ypos2);
	sfw::drawLine(xpos1 + 20, ypos1, xpos2 + 20, ypos2);
	sfw::drawLine(xpos1, ypos1, xpos2 + 20, ypos2 - 100);
	sfw::drawLine(xpos1 + 20, ypos1 + 100, xpos2, ypos2);

}


void paddle2()
{

	if (sfw::getKey('i')) yvel3 = -speed1 * sfw::getDeltaTime();
	if (sfw::getKey('k')) yvel3 = speed1 * sfw::getDeltaTime();


	ypos3 += yvel3;
	ypos4 += yvel3;


	if (ypos4 > 592)
	{
		yvel3 = 0;
	}
	if (ypos3 < 8)
	{
		yvel3 = 0;
	}


	sfw::drawLine(xpos3, ypos3, xpos4, ypos4);
	sfw::drawLine(xpos3 - 20, ypos3, xpos4 - 20, ypos4);
	sfw::drawLine(xpos3, ypos3, xpos4 - 20, ypos4 - 100);
	sfw::drawLine(xpos3 - 20, ypos3 + 100, xpos4, ypos4);

}




