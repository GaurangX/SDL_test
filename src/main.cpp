//============================================================================
// Name        : Particle.cpp
// Author      : Gaurang Upasani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				// setPixel (x, y, R, G, B)
				screen.setPixel (x, y, 128, 0, 255, 255);
			}
		}

		// one pixel data
		screen.setPixel(400, 300, 255, 255, 255, 255);

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
