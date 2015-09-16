#include <iostream>
#include "sfwdraw.h"
#include "paddle.h"
#include <ctime>
#include "Ball.h"


const int WinWidth = 800;
const int WinHeight = 600;

void walls()
{
// top and left
sfw::drawLine(5, 5, 5, WinHeight - 5);
sfw::drawLine(5, 5, WinWidth - 5, 5);

//bottom and right
sfw::drawLine(WinWidth - 5, WinHeight - 5, 5, WinHeight - 5);
sfw::drawLine(WinWidth - 5, WinHeight - 5, WinWidth - 5, 5);

}





int main()
{
	
	std::cout << "Ready to Begin?" << std::endl;

	system("pause");

	sfw::initContext(WinWidth, WinHeight, "Pong!");


	while (sfw::stepContext())
	{
		ball();
		walls();

		
		paddle1();
		paddle2();
		




	}







	sfw::termContext();




}




