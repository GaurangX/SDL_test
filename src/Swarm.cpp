/*
 * Swarm.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#include "Swarm.h"

namespace gru {

Swarm::Swarm() : lastTime(0) {
	m_particles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete [] m_particles;
}

// update each particle
void Swarm::update(int elapsed) {

	int interval = elapsed - lastTime;

	for(int i = 0; i < Swarm::NPARTICLES; i++) {
		m_particles[i].update(interval);
	}
	lastTime = elapsed;
}


} /* namespace gru */
