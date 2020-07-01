//============================================================================
// Name        : Particle.cpp
// Author      : Gaurang Upasani
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
using namespace std;

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	SDL_Window *window = SDL_CreateWindow("Particle Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Quit();
		cout << " Error information ..." << SDL_GetError();
		return 1;
	}

	SDL_Renderer *renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if (texture == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_HEIGHT*SCREEN_WIDTH];

	// Most important function -> set to each pixel as 255 (white)
	memset(buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	//buffer[30000] = 0xFFFFFFFF;

	for (int i = 0; i < SCREEN_HEIGHT*SCREEN_WIDTH; i++){
		buffer[i] = 0xFFFF00FF;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

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

	delete [] buffer;
	SDL_DestroyTexture(texture);
	//SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
