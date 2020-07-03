/*
 * Particle.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#include <stdlib.h>
#include <math.h>
#include "Particle.h"

namespace gru {

Particle::Particle() : m_x(0), m_y(0) {

	init();
}

Particle::~Particle() {}

void Particle::init() {

	// initialize particles to random x,y co-ordinates
	// m_x = ((2.0 * rand())/RAND_MAX) - 1;
	// m_y = ((2.0 * rand())/RAND_MAX) - 1;

	// m_xspeed = 0.001*(((2.0 * rand())/RAND_MAX) - 1);
	// m_yspeed = 0.001*(((2.0 * rand())/RAND_MAX) - 1);

	m_direction = (2.0 * M_PI * rand())/RAND_MAX;

	m_speed = (0.04 * rand()/RAND_MAX);
	m_speed *= m_speed;
}

// interval makes it move at constant speed regarless of screen refresh rate
void Particle::update(int interval) {
/*
	// make each particle move with each update.
	m_x += m_xspeed;
	m_y += m_yspeed;

	if (m_x < -1.0 || m_x >= 1.0) {
		m_xspeed = -m_xspeed;
	}

	if (m_y < -1.0 || m_y >= 1.0) {
		m_yspeed = -m_yspeed;
	}
*/
	m_direction += 0.0004 * interval;

	double xspeed = m_speed *  cos(m_direction);
	double yspeed = m_speed *  sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}
	// randomly pick particles and re-initialize them every 1 in 100 times
	if (rand() < RAND_MAX/1000) {
		init();
	}
}

} /* namespace gru */
