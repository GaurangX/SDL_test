//============================================================================
// Name        : Particle.cpp
// Author      : Gaurang Upasani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace gru;

int main() {

	Screen screen;

	if (screen.Init() == false) {
		cout << " Error initializing SDL." << endl;
	}

	// Main game loop
	while (true) {
		// update particles

		// draw particles
		int elapsed = SDL_GetTicks(); // returns ms.
		// to limit it to 255
		unsigned char r = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char g = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char b = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				// setPixel (x, y, R, G, B)
				screen.setPixel (x, y, r, g, b, 255);
			}
		}

		// one pixel data
		// screen.setPixel(400, 300, 255, 255, 255, 255);

		//set update screen with pixel data
		screen.update();

		// check messages/events
		if (screen.processEvents() ==  false) {
			break;
		}

	}

	screen.close();
	return 0;
}
