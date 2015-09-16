#pragma once
#include <iostream>
#include "sfwdraw.h"
#include "paddle.h"
#include <ctime>



float xpos = 400, ypos = 300; // position
int xvel = 200, yvel = 200;	  // velocity
const float speed = 100;
int x;
int y;
int left = 0;
int right = 0;

void ball()
{
	




	int score[2] = { left , right };



	//random diretion at start
	y = rand() % 2;
	x = rand() % 2;
	if (xpos == 400 && ypos == 300)
	{
		if (x == 1)
		{
			xvel = 200;
		}
		if (x == 0)
		{
			xvel = -200;
		}

	}
	xpos += xvel * sfw::getDeltaTime();
	ypos += yvel * sfw::getDeltaTime();


	sfw::drawCircle(xpos, ypos, 15);

	if (ypos + (15 + 5) > 600)			// I figured this out on my own however i found a way to make it look nicer at http://relativity.net.au/gaming/java/SimpleCollisionDetection.html
	{
		yvel = -yvel;

	}
	if (ypos - (15 + 5) < 0)
	{
		yvel = -yvel;
	}
	//returns to center after score
	if (xpos > 780)
	{
		xpos = 400;
		ypos = 300;
		++left;
		std::cout << "Player 1 scores" << std::endl;
		std::cout << "Player 1 : " << left << "    Player 2 :  " << right << std::endl;
	}
	if (xpos < 20)
	{
		xpos = 400;
		ypos = 300;
		++right;
		std::cout << "Player 2 scores" << std::endl;
		std::cout << "Player 1 : " << left << "    Player 2 :  " << right << std::endl;
	}
	//paddle collison
	if (xpos < xpos1 + 35    //35 = width of paddle + ball     //http://noobtuts.com/cpp/2d-pong-game
		&&
		xpos > xpos2
		&&
		ypos < ypos1 + 100
		&&
		ypos > ypos1
		&&
		ypos > xpos1)
	{
		xvel = -xvel;
	}

	//left side paddle collison
	if (xpos > xpos3 - 35       
		&&
		xpos < xpos4
		&&
		ypos > ypos3 
		&&
		ypos < ypos3 + 100
		&&
		ypos < xpos3)
	{
		xvel = -xvel;
	}

	if (right == 5)
	{
		std::cout << "Player 2 Wins!" << std::endl;
		xvel = 0;
		yvel = 0;
		system("pause");
		sfw::termContext();
	}
	if (left == 5)
	{
		std::cout << "Player 1 Wins!" << std::endl;
		xvel = 0;
		yvel = 0;
		system("pause");
		sfw::termContext();
	}

	
}