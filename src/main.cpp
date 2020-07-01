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
		// check messages/events
		if (screen.processEvents() ==  false) {
			break;
		}
	}

	screen.close();
	return 0;
}
