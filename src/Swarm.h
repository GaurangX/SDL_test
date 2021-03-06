/*
 * Swarm.h
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"


namespace gru {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle *m_particles; // we dont want the m_particles to point else where
	int lastTime;


public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);

	const Particle * const getParticles() { return m_particles; }; //
};

} /* namespace gru */

#endif /* SWARM_H_ */
