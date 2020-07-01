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
	memset(m_buffer, 0x00, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	//buffer[30000] = 0xFFFFFFFF;

	for (int i = 0; i < SCREEN_HEIGHT*SCREEN_WIDTH; i++){
		m_buffer[i] = 0xFFFF00FF;
	}
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	return true;
}

bool Screen::processEvents(){

	return true;
}
void Screen::close(){
	delete [] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}


} /* namespace gru */