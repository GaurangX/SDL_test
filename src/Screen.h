/*
 * Screen.h
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#ifndef SCREEN_H_
#define SCREEN_H_


#include <SDL.h>

namespace gru {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool Init();
	bool processEvents();
	void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B, Uint8 Alpha);
	void update();
	void clear();
	void close();

};

} /* namespace gru */

#endif /* SCREEN_H_ */
