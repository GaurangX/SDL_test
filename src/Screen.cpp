/*
 * Screen.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#include <iostream>
#include "Screen.h"

using namespace std;

namespace gru {

Screen::Screen():
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}

bool Screen::Init() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	 m_window = SDL_CreateWindow("Particle Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		cout << " Error information ..." << SDL_GetError();
		return false;
	}

	m_renderer =  SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[SCREEN_HEIGHT*SCREEN_WIDTH];

	// Most important function -> set to each pixel as 255 (white)
	// memset(m_buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	return true;
}

bool Screen::processEvents() {
	SDL_Event event;
	// this is what closes the screen when click on the left corner with X in it.
	while (SDL_PollEvent (&event)) {
		if(event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B, Uint8 Alpha) {

	if (x < 0  || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		return;
	}


	Uint32 color = 0;
	Alpha = 0xFF;

	color += R;
	color <<= 8;
	color += G;
	color <<= 8;
	color += B;
	color <<= 8;
	color += Alpha;

	// rastering? (x,y) co-ordinate to the index of buffer
	m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::clear() {
	memset(m_buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

void Screen::close() {
	delete [] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}


} /* namespace gru */
