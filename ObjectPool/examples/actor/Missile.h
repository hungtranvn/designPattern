#ifndef MISSILE_H
#define MISSILE_H
#include "Actor.h"
class Missile : public Actor {
public:
	Missile() ;
	~Missile();
	void Update() ;
};
#endif
