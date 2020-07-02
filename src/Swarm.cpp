/*
 * Swarm.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#include "Swarm.h"

namespace gru {

Swarm::Swarm() {
	m_particles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete [] m_particles;
}

void Swarm::update() {
	for(int i = 0; i < Swarm::NPARTICLES; i++) {
		m_particles[i].update();
	}
}


} /* namespace gru */
