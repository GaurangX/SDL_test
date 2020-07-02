/*
 * Particle.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#include <stdlib.h>
#include "Particle.h"

namespace gru {

Particle::Particle() {
	m_x = ((2.0 * rand())/RAND_MAX) - 1;
	m_y = ((2.0 * rand())/RAND_MAX) - 1;

	m_xspeed = 0.001*(((2.0 * rand())/RAND_MAX) - 1);
	m_yspeed = 0.001*(((2.0 * rand())/RAND_MAX) - 1);
}

Particle::~Particle() {}

void Particle::update() {
	m_x += m_xspeed;
	m_y += m_yspeed;

	if (m_x < -1.0 || m_x >= 1.0) {
		m_xspeed = -m_xspeed;
	}

	if (m_y < -1.0 || m_y >= 1.0) {
		m_yspeed = -m_yspeed;
	}
}

} /* namespace gru */
