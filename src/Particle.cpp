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
}

Particle::~Particle() {}

} /* namespace gru */
