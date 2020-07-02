//============================================================================
// Name        : Particle.cpp
// Author      : Gaurang Upasani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <SDL.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace gru;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.Init() == false) {
		cout << " Error initializing SDL." << endl;
	}

	Swarm swarm;

	// Main game loop
	while (true) {

		// draw particles
		int elapsed = SDL_GetTicks(); // returns ms.
		// to limit it to 255
		unsigned char r = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char g = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char b = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

		// update particles
		const Particle * const particles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = particles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, r, g, b, 255);
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
