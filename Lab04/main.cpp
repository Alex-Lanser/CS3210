#include "x11context.h"
#include <unistd.h>
#include <iostream>

int main(void)
{
	// Make my stick figure wave
	GraphicsContext *gc = new X11Context(800, 600, GraphicsContext::BLACK);

	// Eyes
	gc->setColor(GraphicsContext::WHITE);
	gc->drawCircle(350, 175, 10);
	gc->drawCircle(450, 175, 10);
	// Pupils
	gc->setColor(GraphicsContext::BLUE);
	gc->drawCircle(350, 175, 1);
	gc->setPixel(350, 175);
	gc->drawCircle(450, 175, 1);
	gc->setPixel(450, 175);

	// Mouth
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(360, 250, 440, 250);

	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(400, 300, 400, 500);
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(400, 500, 600, 700);
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(200, 700, 400, 500);
	// Arms
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(300, 400, 400, 400); // Left Arm
	gc->drawLine(400, 400, 500, 400); // Right Arm
	gc->setColor(GraphicsContext::GREEN);
	gc->drawCircle(400, 200, 100);
	sleep(1);

	// Begin smile
	// Mouth
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(359, 249, 358, 248);
	gc->drawLine(441, 249, 442, 248);
	sleep(1);

	// Mouth
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(357, 247, 356, 246);
	gc->drawLine(443, 247, 444, 246);
	// Arms
	gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
	gc->drawLine(400, 400, 500, 400);
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(400, 400, 500, 390); // Right Arm
	sleep(1);

	// Mouth
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(355, 245, 354, 244);
	gc->drawLine(445, 245, 446, 244);
	// Arms
	gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
	gc->drawLine(400, 400, 500, 390);
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(400, 400, 500, 380); // Right Arm
	sleep(1);

	// Mouth
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(353, 243, 352, 242);
	gc->drawLine(447, 243, 448, 242);
	// Arms
	gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
	gc->drawLine(400, 400, 500, 380);
	gc->setColor(GraphicsContext::GREEN);
	gc->drawLine(400, 400, 500, 370); // Right Arm
	sleep(1);

	int i = 370;
	while (i >= 300)
	{
		gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
		gc->drawLine(400, 400, 500, i);
		gc->setColor(GraphicsContext::GREEN);
		gc->drawLine(400, 400, 500, i - 10); // Right Arm
		i = i - 10;
		sleep(1);
	}

	for (int i = 0; i < 3; i++)
	{
		gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
		gc->drawLine(400, 400, 500, 290);
		gc->setColor(GraphicsContext::GREEN);
		gc->drawLine(400, 400, 500, 300); // Right Arm
		sleep(1);
		gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
		gc->drawLine(400, 400, 500, 300);
		gc->setColor(GraphicsContext::GREEN);
		gc->drawLine(400, 400, 500, 290); // Right Arm
		sleep(1);
	}

	while (i <= 400)
	{
		gc->setColor(GraphicsContext::BLACK); // Reset previous arm frame
		gc->drawLine(400, 400, 500, i - 10);
		gc->setColor(GraphicsContext::GREEN);
		gc->drawLine(400, 400, 500, i); // Right Arm
		i = i + 10;
		sleep(1);
	}

	gc->setColor(GraphicsContext::BLACK);
	gc->drawLine(353, 243, 352, 242);
	gc->drawLine(447, 243, 448, 242);
	sleep(1);
	gc->drawLine(355, 245, 354, 244);
	gc->drawLine(445, 245, 446, 244);
	sleep(1);
	gc->drawLine(357, 247, 356, 246);
	gc->drawLine(443, 247, 444, 246);
	sleep(1);
	gc->drawLine(359, 249, 358, 248);
	gc->drawLine(441, 249, 442, 248);

	gc->setColor(GraphicsContext::RED);
	gc->drawLine(359, 251, 358, 252);
	gc->drawLine(440, 251, 441, 252);
	sleep(1);
	gc->drawLine(357, 253, 356, 254);
	gc->drawLine(442, 253, 443, 254);
	sleep(1);
	gc->drawLine(355, 255, 354, 256);
	gc->drawLine(444, 255, 445, 256);
	sleep(1);
	gc->drawLine(353, 257, 352, 258);
	gc->drawLine(446, 257, 447, 258);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(355, 185, 355, 188);
	sleep(1);
	gc->setColor(GraphicsContext::BLACK);
	gc->drawLine(355, 185, 355, 188);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(355, 188, 355, 191);
	sleep(1);
	gc->setColor(GraphicsContext::BLACK);
	gc->drawLine(355, 188, 355, 191);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(355, 191, 355, 194);
	sleep(1);
	gc->setColor(GraphicsContext::BLACK);
	gc->drawLine(355, 191, 355, 194);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(355, 194, 355, 197);
	sleep(1);
	delete gc;

	return 0;
}