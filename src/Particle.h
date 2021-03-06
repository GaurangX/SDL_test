/*
 * Particle.h
 *
 *  Created on: Jul 1, 2020
 *      Author: valiantswabian
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace gru {

struct Particle {
    // by default struct members are public.
	// if this are private and used with Get method, it is bad for efficiency
	// will refresh every time screen refreshes.
	double m_x;
	double m_y;

	//double m_xspeed;
	//double m_yspeed;
private:
	double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();

	void update(int interval);
};

} /* namespace gru */

#endif /* PARTICLE_H_ */
