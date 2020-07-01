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

	bool quit = false;
	SDL_Event event;

	// Game loop
	while (!quit) {
		// update particles
		// draw particles
		// check messages/events

		while (SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	screen.close();
	return 0;
}
